#include <iostream>
#include <vector>
#include <list>
#include <bits/stdc++.h>
 
using namespace std;
 
//vector<tuple<int, int, int>> acts, sol;
//vector<int> indice;
/*
#define 

void bucket_sort(vector<tuple<int,int,int>>& activs){
    int n = activs.size();
    vector<list<tuple<int,int,int>>> buckets(2*n+1);
    for(auto a : activs){
        if ()
    }
}*/
 
int mayor_sub_conjunto(const vector<tuple<int,int,int>>& activs, vector<tuple<int,int,int>>&  sol) {
    //ordenar
    sort(activs.begin(),activs.end(), comparar_por_elem);
    sol[0] = activs[0];
    int t_iAnterior = get<1>(activs[0]);
    int contador = 1;
    for (int i = 1; i < activs.size(); i++) {
        if (get<0>(activs[i]) >= t_iAnterior) {
            t_iAnterior = get<1>(activs[i]);
            sol[contador] = activs[i];
            contador++;
        }
    }
    return contador;
}
 
//aux sort
bool comparar_por_elem(tuple<int,int,int> a, tuple<int,int,int> b){
    return get<1>(a) < get<1>(b);
}
 
int main() {
    int actividades; cin >> actividades;
    vector<tuple<int, int, int>> acts = vector<tuple<int,int,int>>(actividades);
    vector<tuple<int, int, int>> sol = vector<tuple<int,int,int>>(actividades);
 
    for (int i = 0; i < actividades; i++) {
        int inicio, final;
        cin >> inicio >> final;
        int indice = i + 1;
 
        acts[i] = make_tuple(inicio,final,indice);
    }
 
    
 
    /*for (int i = 0; i < actividades; i++){
        cout << get<0>(acts[i]) << get<1>(acts[i]) << get<2>(acts[i]) << endl;
    }*/
 
    //hacer lo que dice el ej
    int cantActsSol = mayor_sub_conjunto(acts, sol);
    cout << cantActsSol << endl;
    for (int i = 0; i < cantActsSol; i++) {
        cout << get<2>(sol[i]) << " ";
    }
    cout << endl;
 
    return 0;
}
 
