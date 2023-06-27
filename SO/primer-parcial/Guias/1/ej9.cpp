#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


void juan(){
    write(1,"Soy Juan\n\0",10);
    sleep(1);
    wait(NULL);
    pid_t pid_1 = fork();
    if (pid_1==0){
        write(1,"Soy Jorge\n",10);
        sleep(1);
        exit(EXIT_SUCCESS);
    }else{
        exit(EXIT_SUCCESS);
    }
    
}

void julieta(){
    write(1,"Soy Julieta\n",12);
    sleep(1);
    pid_t pid = fork();
    if (pid == 0){
        write(1,"Soy Jennifer\n\0",14);
        sleep(1);
        exit(EXIT_SUCCESS);
    }else{
        exit(EXIT_SUCCESS);
    }
}

int main(int argc, char const *argv[]){
    pid_t pid = fork();
    if (pid == 0){
        julieta();
    }else{
        juan();
    }
}