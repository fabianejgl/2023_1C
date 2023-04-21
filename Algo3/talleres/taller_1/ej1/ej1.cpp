#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// Completar
int shopaholic(int n, vector<int> precios, int contador, int suma_parcial) {    
    //if (contador==0) return suma_parcial;
    int indice = n-3;
while(contador!=0){
    suma_parcial += precios[indice];
    indice -= 3;
    contador--;
    }
    return suma_parcial;
}

int main(int argc, char *argv[]) {
    int t; cin >> t;

    for (size_t i = 0; i < t; i++){    
        int n; cin >> n;
        vector<int> precios(n,0);

        for(int i = 0; i < precios.size(); ++i){
            cin >> precios[i];
        }

        sort(precios.begin(),precios.end());

        int contador = n/3;
        int res = shopaholic(n,precios,contador,0);
        cout << res;
        cout << endl;
    }
    return 0;
}