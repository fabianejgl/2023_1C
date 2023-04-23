#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include "constants.h"
#include "mini-shell-parser.c"


static void runChildren(char ** prog, int pipes[][2], int n, int program_count){
	//REDIRECCIONO
	for(int i = 0; i < program_count - 1; ++i){
		//N = ÍNDICE QUE PASO POR PARÁMETRO
		if( i == n - 1){
			//ANTE-ULTIMO CASO
			close(pipes[i][PIPE_WRITE]);
			dup2(pipes[i][PIPE_READ], STD_INPUT);	//IMPRIME PANTALLA, POR ESO SE USAN COUNT-1 PIPES??????????????
		}
		else if(i == n){
			//ULTIMO caso
			close(pipes[i][PIPE_WRITE]);
			dup2(pipes[i][PIPE_READ], STD_OUTPUT);
		}
		else{
			close(pipes[i][PIPE_WRITE]);
			close(pipes[i][PIPE_READ]);
		}
	}

	//EJECUTO
	execvp(prog[0],prog);
}


//PROGS es un vector hacia... donde empieza cada instruccion?
static int run(char ***progs, size_t count)
{	
	int r, status;

	//Reservo memoria para el arreglo de pids
	//TODO: Guardar el PID de cada proceso hijo creado en children[i]
	pid_t *children = malloc(sizeof(*children) * count);

	//Si tengo COUNT instrucciones creo vector PIPES de COUNT-1 * 2 lugares, el -1 es porque para el último no necesito creo
	int pipes[count - 1][2];

	for (int i = 0; i < count - 1; ++i){
		int status = pipe(pipes[i]);	//qué devuelve el pipe? Sé que int, pero status a que se refiere?
		if (status==-1){				//en qué caso podría entrar acá????
			exit(-1);
		}		
	}

	for (int i = 0; i < count; ++i){
		//Hijo
		children[i] = fork();	//en la pos i SE GUARDA EL PID DEL HIJO i
		if (children[i]==0){	//????????????????????????????????? Nunca entraría acá o sí?
			runChildren(progs[i], pipes, i, count);	//pasa parámetros
		}
	}
	
	//cierra todos los pipes del 0 al count-1
	for (int i = 0; i < count; ++i){
		close(pipes[i][0]);
		close(pipes[i][1]);
	}
	

	//TODO: Pensar cuantos procesos necesito
	//TODO: Pensar cuantos pipes necesito.

	//TODO: Para cada proceso hijo:
			//1. Redireccionar los file descriptors adecuados al proceso
			//2. Ejecutar el programa correspondiente


	//Espero a los hijos y verifico el estado que terminaron
	for (int i = 0; i < count; i++) {
		waitpid(children[i], &status, 0);

		if (!WIFEXITED(status)) {
			fprintf(stderr, "proceso %d no terminó correctamente [%d]: ",
			    (int)children[i], WIFSIGNALED(status));
			perror("");
			return -1;
		}
	}
	r = 0;
	free(children);

	return r;
}


int main(int argc, char **argv)
{
	int programs_count;
	char*** programs_with_parameters = parse_input(argv, &programs_count);

	printf("status: %d\n", run(programs_with_parameters, programs_count));

	fflush(stdout);
	fflush(stderr);

	return 0;
}
