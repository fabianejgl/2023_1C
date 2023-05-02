#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


int nietoTermino = 0;
int N;

void handler(){
    nietoTermino = 1;
}

void ejecutarHijo( int i, int pipes[][2]) {
    for(int j = 0; j < (N*2); j++){
        if(j==i || j == N+i){
            continue;
        } else {
            close(pipes[i][0]);
            close(pipes[i][1]);
        }
    }
    signal(SIGTERM, handler);
    int numero;
    read(pipes[i][0],&numero, sizeof(numero));
    int pipeNieto[2];
    pipe(pipeNieto);
    pid_t nieto = fork();
    if (nieto == 0){
        ejecutarNieto(pipeNieto, getppid(), numero);
    } else {
        while(!nietoTermino){

        }
        write(pipes[N+i][1], &nietoTermino, sizeof(nietoTermino));
        int resultado;
        read(pipeNieto[0], &resultado, sizeof(resultado));
        write(pipes[N+i][1], &numero, sizeof(numero));
        write(pipes[N+i][1], &resultado, sizeof(resultado));
    }
    exit(0);
}



void ejecutarNieto(int pipeNieto[2], pid_t padre, int numero) {
    int resultado = calcular(numero);
    kill(padre, SIGTERM);
    write(pipeNieto[1], &resultado, sizeof(resultado));
    exit(0);
}
