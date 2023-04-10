#include <stdio.h>
#include <vector>
#include <stdlib.h>

using namespace std;

int cuad_mag(int m, vector<vector<int>> &s, int i, int j, vector<int> &c, vector<int> &p, int diag1, int diag2, int indice) {
    //si kesimo > a 7040 sabiendo n = 4 devuelvo -1, sino recorro al pedo xd
    int n = s.size();
    if (j == n) return cuad_mag(m, s, i + 1, 0, c, p, diag1, diag2, indice); // Siguiente fila
    if (i == n){
        if(indice es kesimo tonces imprimo cuadrado){
                //IMPRIMO
        // for (int i = 0; i < n; i++){
        //     for (int j = 0; j < n; j++) {
        //         printf("%d ", s[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");
        }
        SINO SUMO 1 AL INDICE ACTUAL
        return 1;
    }    
    int r = 0;

    for (int k = 1; k <=n*n ; k++){
        //Checkeo si está disponible
        if (c[k-1] == 1) continue;

        // Chequeo si la suma parcial de la fila actual (p[i]) + k es > m
        if (p[i] + k > m) continue;

        // En los casos que j==n-1 chequeo si la suma de la FILA es == m
        if (j == n-1 && p[i] + k != m) continue;

        // Chequeo si la suma parcial de la COL actual (p[n+i]) + k es > m
        if (p[n + j] + k > m) continue;

        // Cheque si la suma de columna al terminarla es == m
        if (i == n-1 && p[n + j] + k != m) continue;

        // Check si TOY EN DIAGONAL1 y si la sum parcial de diag1 es > m
        if (i == j && diag1 + k > m) continue;

        //Chequea si al terminar la diag1 es o no == m
        if (i == j && i == n-1 && diag1 + k != m) continue;

        // Check si TOY EN DIAGONAL2 y si la sum parcial de diag2 es > m
        if (i == n-j-1 && diag2 + k > m) continue;

        //Chequea si al terminar la diag2 es o no == m
        if (i == n-j-1 && i == n - 1 && diag2+ k != m) continue;


        //Si llega acá...
        s[i][j] = k;        //usa el k actual
        c[k - 1] = 1;       //pone en 1 el elemento
        p[i] += k;          //agrega a suma parcial fila
        p[n + j] += k;      //agrega a suma parfial col
        if (i==j) diag1 += k;   //suma parcial diag1
        if (i==n-j-1) diag2 += k;   //suma parcial diag2

        r += cuad_mag(m, s, i, j + 1, c, p, diag1, diag2, indice);  //se fija soluciones habiendo tomado k actual, y abajo lo quita apra ver las soluciones sin esa

        // Backtrack.
        c[k - 1] = 0;       //borra k actual
        p[i] -= k;          //resta a parcial fila
        p[n + j] -= k;      //resta a parcial col
        if (i==j) diag1 -= k;        //resta aprcial diag1
        if (i==n-j-1) diag2 -= k;    //resta parcial diag 2

        //pasa a siguiente k
    }
    return r;
}


int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    int kesimo = atoi(argv[2]);

    int indice;
    if (kesimo>= 7040) {
        //printf("-1");
        return -1;
    } else if (kesimo < 416) {  //1
        indice = 0;
    } else if (kesimo < 816) {  //2
        indice = 416;
    } else if (kesimo < 1220) {  //3
        indice = 816;
    } else if (kesimo < 1696) {  //4
        indice = 1220;
    } else if (kesimo < 2128) {  //5
        indice = 1696;
    } else if (kesimo < 2584) {  //6
        indice = 2124;
    } else if (kesimo < 3044) {  //7
        indice = 2580;
    } else if (kesimo < 3520) {  //8
        indice = 3040;
    } else if (kesimo < 3996) {  //9
        indice = 3520;
    } else if (kesimo < 4456) {  //10
        indice = 3996;
    } else if (kesimo < 4912) {  //11
        indice = 4456;
    } else if (kesimo < 5344) {  //12
        indice = 4912;
    } else if (kesimo < 5820) {  //13
        indice = 5344;
    } else if (kesimo < 6224) {  //14
        indice = 5820;
    } else if (kesimo < 6624) {  //15
        indice = 6224;    
    } else if (kesimo < 7040) { //16
        indice = 6624;
    }

    // Inicializo parámetros
    int m = (n * n * n + n) / 2;                //num mag, item E
    int diag1 = 0;                              //suma parcial diagonal1
    int diag2 = 0;                              //suma parcial diagonal2
    vector<vector<int>> s(n, vector<int>(n));   // creo cuadrado
    vector<int> c(n * n);                       // vector de nums a usar
    vector<int> p(2 * n);                       //sumasparciales de filas y cols


    int r = cuad_mag(m, s, 0, 0, c, p, diag1, diag2, indice);
    printf("El %d° cuadrado mágico de orden %dx%d es (con podas): %d\n",kesimo, n, n, r);       //en realidad acá no debería retornar nada

    return 0;
}