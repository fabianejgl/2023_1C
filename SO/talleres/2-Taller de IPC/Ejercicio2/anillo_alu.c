#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include "constants.h"

int generate_random_number(){
	return (rand() % 50);
}

int main(int argc, char **argv)
{	
	//Funcion para cargar nueva semilla para el numero aleatorio
	srand(time(NULL));

	int status, pid, n, start, buffer;
	n = atoi(argv[1]);			//número de hijos
	buffer = atoi(argv[2]);		//núm que se envía
	start = atoi(argv[3]);		//hijo que recibe mensaje

	if (argc != 4){ printf("Uso: anillo <n> <c> <s> \n"); exit(0);}
    
/* COMPLETAR */
    printf("Se crearán %i procesos, se enviará el caracter %i desde proceso %i \n", n, buffer, start);

	//Creo pipes, van a ser n porque el último también se conectará con el primero
	int pipes[n][2];
	int pipe_al_primer_hijo[2];	//Este conectará al primer hijo con el padre
	int pipe_al_padre[2];		//Este conectará con el padre.

	//Acá irían que si algún pipe no se creo bien pongo exit(-1)

	for (int i = 0; i < n; i++){
		if (fork() == 0){
			//entran hijos
			if(i == start){
				ejecutar_start(pipe_al_padre, pipe_al_primer_hijo, pipes, i, n);
			}else{
				ejecutar_hijo_comun(pipes, i, n);
			}
		}
	}
	

/* COMPLETAR */

}