#include <thread>
#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>

int N = 100;

using namespace std;

void funcion(int i, int j){
    for (int i = inicio; i < final; i++)
    {
        /* code */
    }
    
}

int main(int argc, char const *argv[]){
    vector<int> v1(N);
    vector<int> v2(N);
    iota(v1.begin(), v1.end(), 1);
    iota(v2.begin(), v2.end(), N + 1);

    
    vector<thread> threads;
    for(int i = 0; i <5; ++i){

        threads.emplace_back(funcion, );
    }

    return 0;
}
