#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

//solucion simple/naive, donde se generan muchos
//cuadrados de más que no son solución
bool es_valido(vector<vector<int>> &s){
    //número mágico calculo
    int m = 0;
    for(int i = 0; i < s.size(); i++){
        m += s[i][0];
    }

    //Verif columnas y filas = m
    for (int i = 0; i < s.size(); i++){
        int suma_col = 0;               //suma de col y fila de indice i
        int suma_fila = 0;
        for (int j = 0; j < s.size(); j++){
            suma_fila += s[i][j];       //sumo elems fila y col donde esto
            suma_col += s[j][i];
        }
        if(suma_col != m || suma_fila != m){    //verifico
            return false;
        }
    }

    //Verif diagonales == m
    int diag1 = 0;
    int diag2 = 0;
    for (int i = 0; i < s.size(); i++){
        diag1 += s[i][i];
        diag2 += s[i][s.size()-1-i];
    }

    if(diag1 != m || diag2 != m){
        return false;
    }
    
    return true;
}



//Inicio codigo de cuad magico, params: sol actual, numero i y j = pos actual, 
int cuad_mag(vector<vector<int>> &s, int i, int j, vector<int> &c){
    //caso base: fijarme siterminé de recorrer el cuadrado
    int n = s.size();
    if (j==n) return cuad_mag(s,i+1,0,c); //llegar a n es salir del cuadrado
    if (i==n) return es_valido(s);      //llegar a n es salir del cuadrado

    //Si no terminó:
    int r = 0; //cant sols
    //hacer un for con todas las opciones llamando a las posibles soluciones
    for(int k = 0; k < n*n; k++){   // k in (0 a n*n-1)
        if(c[k]==0){    //si el num k+1 ya fue seleccionado(1) hago k++
            s[i][j] = k+1;              //agrego num
            c[k] = 1;                   //marco como agregado
            r += cuad_mag(s,i,j+1,c);   //llamo a sol parcial con k usada
            c[k] = 0;                   //la desmarco para BACKTRACK. En la proxima solucion la tendría disponible
        }
    }
    return r;
}


int main(int argc, char* argv[]){
    int n = atoi(argv[1]);  //k = num que quiero averiguar si se obtiene

    vector<vector<int>> s(n,vector<int>(n));    //creo cuadrado mágico
    vector<int> c(n*n);                         //creo vector de candidatos "binario"
    
    int r = cuad_mag(s,0,0,c);
    printf("La cantidad de cuads mágicos en %dx%d es: %d\n", n, n, r);
}