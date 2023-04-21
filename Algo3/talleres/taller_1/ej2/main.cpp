#include <iostream>
#include <vector>
#include <bits/stdc++.h>

int mayor_actual = 0;

using namespace std;
void max_capacidad(int capacidad, vector<int>& precios, vector<int>& pesos, int indice, int sol_parcial){
    if(capacidad < 0) return;                   //poda si no cumple la capacidad, return ALGO? o solo return?
    int n = precios.size();
    if(indice == n){                              //si terminé me fijo si es mejor que la sol actual, sino no hago nada
        if(sol_parcial > mayor_actual){
            mayor_actual = sol_parcial;
            return;
        }else{
            return;
        }
    }

    max_capacidad(capacidad, precios, pesos, indice + 1, sol_parcial);
    max_capacidad(capacidad - pesos[indice], precios, pesos, indice+1, sol_parcial + precios[indice]);
}

// Completar
int shopaholic_2(vector<int>& precios, vector<int>& pesos, vector<int>& capacidad) {    //int sol_parcial?
    int max_total = 0;
    int n = capacidad.size();
    for(int i = 0; i < n; ++i){
        max_capacidad(capacidad[i], precios, pesos, 0, 0);  //0 = indice amigos
        max_total += mayor_actual;                          //sumo lo que debería tener en mayor_actual
    }
    return max_total;
}

int main(int argc, char *argv[]) {
    int t; cin >> t;

    for (size_t i = 0; i < t; i++){    
        int n; cin >> n;
        vector<int> precios(n,0);
        vector<int> pesos(n,0);

        for(int i = 0; i < precios.size(); ++i){
            cin >> precios[i];
            cin >> pesos[i];
        }

        int num_personas; cin >> num_personas;
        vector<int> capacidad(num_personas,0);
        for(int i = 0; i < capacidad.size(); ++i){
            cin >> capacidad[i];
        }

        int res = shopaholic_2(precios, pesos, capacidad);   //el 0 es de indice de amigos
        cout << "La respuesta es: " << res;
        cout << endl;
    }
    return 0;
}