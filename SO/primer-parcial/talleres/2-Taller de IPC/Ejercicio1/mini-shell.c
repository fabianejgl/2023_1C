#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include "constants.h"
#include "mini-shell-parser.c"


static void runChildren(char ** prog, int pipes[][2], int n, int program_count){	//n = hijo actual
	//REDIRECCIONO
	for(int i = 0; i < program_count - 1; ++i){	//cierra todo menos los 2 que usa en hijo i (n) 
		//N = ÍNDICE QUE PASO POR PARÁMETRO
		if( i == n - 1){
			//si llegó al proceso/hijo anterior
			close(pipes[i][PIPE_WRITE]);			//cierro su write porque nadie le va escribir
			dup2(pipes[i][PIPE_READ], STD_INPUT);	//
		}
		else if(i == n){
			//ULTIMO caso
			close(pipes[i][PIPE_WRITE]);
			dup2(pipes[i][PIPE_READ], STD_OUTPUT);
		}
		else{
			//cierra todos los demás casos
			close(pipes[i][PIPE_WRITE]);
			close(pipes[i][PIPE_READ]);
		}
		execvp(prog[0][0],prog[0]);

	}else if(n == (program_count-1)){
		dup2(pipes[0][PIPE_READ], STD_INPUT);	//lee del ultimo pipe donde se guardó algo

		for (int i = 0; i < program_count; i++){
			close(pipes[i][PIPE_WRITE]);
			close(pipes[i][PIPE_READ]);
		}

		execvp(prog[n][0],prog[n]);
	}else{
		dup2(pipes[n-1][PIPE_READ], STD_INPUT);	//lee del ultimo pipe donde se guardó algo.
		dup2(pipes[n][PIPE_WRITE], STD_INPUT);	//escribe en su propio pipe.


		for (int i = 0; i < program_count; i++){
			close(pipes[i][PIPE_WRITE]);
			close(pipes[i][PIPE_READ]);
		}

		execvp(prog[n][0],prog[n]);
	}
}


//PROGS es un vector hacia... donde empieza cada instruccion?
static int run(char ***progs, size_t count)
{	
	int r, status;

	//Reservo memoria para el arreglo de pids
	//TODO: Guardar el PID de cada proceso hijo creado en children[i]
	pid_t *children = malloc(sizeof(*children) * count);

	//count-1 porque al ultimo no lo conecta con nada
	int pipes[count - 1][2];

	for (int i = 0; i < count - 1; ++i){
		int status = pipe(pipes[i]);	//qué devuelve el pipe? Sé que int, pero status a que se refiere?		
	}

	for (int i = 0; i < count; ++i){
		//Hijo
		children[i] = fork();	//en la pos i SE GUARDA EL PID DEL HIJO i
		if (children[i]==0){	//Para todos los hijos hace esto, ya que son == 0
			runChildren(progs[i], pipes, i, count);	//pasa parámetros
		}
	}
	
	//cierra todos los pipes por las dudas al final, para le padre y ¿cada hijo?.
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
