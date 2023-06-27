#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

using namespace std;

//punto A
void hijo() {
    int val;
    for(int i=0; i<10; i++) {
        val = breceive(get_current_pid());
        bsend(get_current_pid()-1, val+1);
    }
}

int main() {
    pid_t pid = fork();
    if (pid == 0){
        hijo();
        exit(0);
    }

    int val = 0;
    for(int i=0; i<10; i++) {
        bsend(pid, val);        //pid es el del hijo
        val = breceive(pid);
    }
    return 0;
}

//punto B
void hijo_1() {
    int val;
    for(int i=0; i<10; i++) {
        val = breceive(get_current_pid());
        bsend(get_current_pid()-1, val+1);
    }
    exit(EXIT_SUCCESS);
}

void hijo_2() {
    int val;
    for(int i=0; i<10; i++) {
        val = breceive(get_current_pid());
        bsend(get_current_pid()-2, val+1);  //preguntar si está bien -2
    }
    exit(EXIT_SUCCESS);
}

int main() {
    pid_t pid_1 = fork();
    if (pid_1 == 0){
        hijo();
        exit(0);
    }

    pid_t pid_2 = fork();
    if (pid_2 == 0){
        hijo();
        exit(0);
    }


    int val = 0;
    while (val ==! 50){
        bsend(pid_1, val);        //pid es el del hijo
        val = breceive(pid);

        bsend(pid_2, val);        //pid es el del hijo
        val = breceive(pid);
    }
    return 0;
}

//punto C
//???