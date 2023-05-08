#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

mutex mtx;  //variable compartida por todos los threads por estar afuera de todo

void f (int i) {
    lock_guard<mutex> lockk(mtx);
    cout << " Hello thread:" << i << endl;
    this_thread::sleep_for(100ms);
    cout << " Bye thread:" << i << endl;
}

int main(int argc, char const *argv[]){
    // lanzamos un thread
    
    for (int i = 0; i < 5; i++){
        vector<thread> threads;
        cout << "------Iteración: "<< (i+1) << "------" << endl;

        for(int j = 0; j <10; ++j){
            threads.emplace_back(f,j);
        }

        for(auto &t: threads){
            t.join();
        }

        cout << endl;
        this_thread::sleep_for(200ms);
    }


    //sleep(1);
    cout<< 1/0 << endl;
    return(0);
}
//NO ERA LA IDEA DEL EJERCICIO, DEBERIAN IMPRIMIR EN CUALQUIER ORDEN