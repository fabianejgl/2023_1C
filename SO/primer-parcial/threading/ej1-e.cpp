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
    for (int j = 0; j < 5; j++)    {
    //1ra opción
        // mtx.lock();
        // cout << " Hello thread:" << i << endl;
        // this_thread::sleep_for(100ms);       //eso hace que salga lo mas posible en orden, pero no garantiza
        // cout << " Bye thread:" << i << endl;
        // mtx.unlock();

    //2da opción, con lockguard creando un SCOPE
        {   //creo scope
            lock_guard<mutex> lock(mtx);
            cout << " Hello thread:" << i << endl;
            this_thread::sleep_for(100ms);
            cout << " Bye thread:" << i << endl;

        }

        this_thread::sleep_for(100ms);
    }
}

int main(int argc, char const *argv[]){
    // lanzamos un thread
    vector<thread> threads;

    for(int i = 0; i <10; ++i){
        threads.emplace_back(f,i);
    }

    for(auto &t: threads){
        t.join();
    }

    //sleep(1);
    return(0);
}