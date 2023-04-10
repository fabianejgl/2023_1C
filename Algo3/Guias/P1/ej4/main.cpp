#include <stdio.h>
#include <vector>

using namespace std;

// Global variables.
vector<int> res;
int min_sum = -1;

void f(vector<vector<int>> &m, vector<int> &candidato, vector<int> &sol_parcial, int k, int s) {        //paso como parámetro s
    int n = m.size();                                           //asigno n
    if (k == n) {                                               //si llego a n
        s += m[sol_parcial[n - 1]][sol_parcial[0]];             //sumo a S el elemento en la posicion de fila [n-1] [0]
        if (min_sum == -1 || s < min_sum) {                 //si es -1 o es menor que la minima suma actual, tonces es la mejor sol hasta ahora
            res = sol_parcial;
            min_sum = s;
        }
    } else {
        for (int i = 0; i < n; i++) {                           //para i de 0 a n-1
            if (candidato[i] != 0) continue;                    //si candidado[i] no es 0 sigue, osea si no está en primer for llamado
            candidato[i] = 1;                                   //lo pone en 1
            sol_parcial[k] = i;                                 //lo pone en sol_parcial, con el for hago que todos los elems de 1 a n se pongan ahí al menos una vez, y luego a partir de if entro en sus ramas
            int d = (k >= 1) ? m[sol_parcial[k - 1]][sol_parcial[k]] : 0;   //si k>=1 le asigno la matriz, sino le asigno 0, La condición no debería ser k >= 0
            if (min_sum == -1 || s + d < min_sum) {             //poda
                f(m, candidato, sol_parcial, k + 1, s + d);
            }
            // Backtrack
            candidato[i] = 0;
        }
    }
}

int main(int argc, char *argv[]) {
    // Initialize matrix.
    int n = 4;
    vector<vector<int>> m = vector<vector<int>>(n);
    m[0] = {0,  1,  10, 10};
    m[1] = {10, 0,  3,  15};
    m[2] = {21, 17, 0,  2};
    m[3] = {3,  22, 30, 0};

    // Initialize candidates and solution vectors.
    vector<int> c = vector<int>(n);
    vector<int> a = vector<int>(n);

    // Calculate solution.
    f(m, c, a, 0, 0);

    // Print solution.
    printf("min sum = %d\n", min_sum);
    for (int i = 0; i < n; i++) {
        printf("𝜋(%d) = %d\n", i + 1, res[i] + 1);
    }

    return 0;
}