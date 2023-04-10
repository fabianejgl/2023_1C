#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

vector<int> res;
int max_sum = -1;

//en vez de devolver imprimir con printf
void subconj_matriz(vector<vector<int>> m, int k, int i, vector<int> a, int suma_parcial){
    int n = m.size();
    if (k == 0){
        if(suma_parcial > max_sum){
            res = a;
            max_sum = suma_parcial;
        }
    } else if (i < n) { //si es n ya terminó y se quedó con el ultimo max_sum
        int d = 0;
        for (int j = 0; j < a.size(); j++){
            if(i != a[j]){
                d += m[i][a[j]] * 2;
            }else{
                d += m[i][a[j]];    
            }
        }
        a.push_back(i);
        subconj_matriz(m,k-1,i+1,a,suma_parcial + d);
        a.pop_back();
        subconj_matriz(m,k,i+1,a,suma_parcial);
    }
    return;
}

    // //Calculo suma de fila/columna actual:
    // for()

    // //Backtracking:
    // a.push_back(i);
    // subconj_matriz(m, k, i+1, a, s);
    // a.pop_back();
    // subconj_matriz(m, k, i+1, a, s);
    // return;

int main(int argc, char const *argv[]){
    int k = atoi(argv[1]);
    //Inicializo matriz acá

    int n = 4;
    vector<vector<int>> m(n, vector<int>(n));

    // m[0] = {0, 1, 1, 1};
    // m[1] = {1, 0, 5,  2};
    // m[2] = {1, 5, 0,  10};
    // m[3] = {1, 2, 10,  0};

    m[0] = {1, 5, 3, 9};
    m[1] = {5, 0, 2, 1};
    m[2] = {3, 2, 8, 4};
    m[3] = {9, 1, 4, 6};

    //guardo vector de tamaño k
    vector<int> a;
    //a.reserve(k);    

    subconj_matriz(m,k,0,a,0);

    //Imprimir solucion
    printf("La solución es: ");
    for(int j; j<res.size();j++){
        printf("%d ", res[j]);
    }
    printf("\n");

    printf("La suma máxima es: %d\n", max_sum);
    return 0;
}
