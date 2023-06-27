#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


// using namespace std;
//PREGUNTAR si esto es lo que se pide:

void system_new(const char *arg){
    pid_t pid = fork(); // Crear un proceso hijo
    if (pid == 0) {
        //Algo así pide, así figura en MAN SYSTEM.
        execl("/bin/sh", "sh", "-c", arg, (char *)0);
    } else {
        wait(NULL);
    }
}