#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

//Acá hice ITEM C Y D.

using namespace std;

mutex mtx;  //variable compartida por todos los threads por estar afuera de todo

void f (int i) {
    this_thread::sleep_for(1000ms * i);         //Con este sleep fuerzo el orden
    cout << " Hello thread:" << i << endl;
}

int main(int argc, char const *argv[]){
    vector<thread> threads;

    for(int i = 0; i <10; ++i){
        threads.emplace_back(f,i);              //crea el thread al momento de colocarlo. 
    }

    for(auto &t: threads){
        t.join();
    }

    //sleep(1);
    return(0);
}