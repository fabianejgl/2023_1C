#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

//5.b. Agrego los waits para que esperen a que terminen sus hijos antes de seguir ellos.

void funcion_homer(){
    //No es nesecario hacer pid_1 pid_2 pid_3, pues
    pid_t pid_1 = fork();
    if(pid_1 == 0){
        printf("Soy Bart\n");
        exit(EXIT_SUCCESS);
    }else{
        wait(NULL);
    }

    pid_t pid_2 = fork();
    if(pid_2 == 0){
        printf("Soy Lisa\n");
        exit(EXIT_SUCCESS);    
    }else{
        wait(NULL);
    }

    pid_t pid_3 = fork();
    if(pid_3 == 0){
        printf("Soy Maggie\n");
        // sleep(1);
        exit(EXIT_SUCCESS);    
    }else{
        wait(NULL);
    }
    printf("Soy Homero\n");
    // sleep(1);
    exit(EXIT_SUCCESS);
}

int main(){
    pid_t pid = fork();
    if (pid==0){
        funcion_homer();
    }else{
        wait(NULL);
        printf("Soy Abraham\n");
    }
    exit(EXIT_SUCCESS);
}