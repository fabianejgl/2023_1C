
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <thread>

using namespace std;

void f () {
    this_thread::sleep_for(500ms);      //para dormir a un thread.
    cout << " Hello thread " << endl;
}

//Procesos principal
int main(int argc, char const *argv[]){
    // lanzamos un thread
    for(int i = 0; i < 10; ++i){
        new thread(f);
    }
    sleep(1);
    return(0);
}