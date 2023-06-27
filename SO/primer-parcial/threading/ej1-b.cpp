#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void f () {
    this_thread::sleep_for(500ms);
    cout << " Hello thread " << endl;
}

int main(int argc, char const *argv[]){
    // lanzamos un thread
    vector<thread> threads;

    for(int i = 0; i<10; ++i){
        //push back no se pueda -> un thread no es COPYABLE
        threads.emplace_back(f);    //crea el thread al momento de colocarlo.
    }

    for(auto &t: threads){
        //opcion1
        t.join();
        //opcion2
        //t.detach();
    }

    //sleep(1);
    return(0);
}