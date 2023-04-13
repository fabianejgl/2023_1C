#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


void funcion_homer(){
    //No es nesecario hacer pid_1 pid_2 pid_3, pues
    printf("Soy Homero\n");
    pid_t pid_1 = fork();
    if(pid_1 == 0){
        printf("Soy Bart\n");
        exit(EXIT_SUCCESS);
    }

    pid_t pid_2 = fork();
    if(pid_2 == 0){
        printf("Soy Lisa\n");
        exit(EXIT_SUCCESS);
    }

    pid_t pid_3 = fork();
    if(pid_3 == 0){
        printf("Soy Maggie\n");
        exit(EXIT_SUCCESS);
    }
    

    exit(EXIT_SUCCESS);
}

int main(){
    printf("Soy Abraham\n");
    pid_t pid = fork();
    if (pid==0){
        funcion_homer();
        exit(EXIT_SUCCESS);
    }else{
        sleep(1);   //por qué se imprime antes que los otros?
    }
    return 0;
}