#include <stdio.h>
#include <stdlib.h>
#include <vector>

//NOTA: se puede agregar una PODA más teniendo en cuenta
//la suma total del resto de elementos, ítem H del 1
//hacerlo o ver ej de honi


using namespace std;
//Permite tener un alcance directo a todas las funciones declaradas en un espacio de nombres "std", es decir, 
//las funciones que normalmente llamarías como "std::cout" solo tendrías que usar "cout".


//Implementación que me devuelve la primer solución, sin podas.
bool subset_sum(vector<int> &c, int i, int j){
    if (j < 0) return false;            //PODA1: ya que a J, que es el K le voy restando los que encuentro y si es menor a 0 automaticamente descarto la opción        

    if (i == 0) return (j == 0);        //Caso base, chequeo si es solución válida.

    //BACKTRACKING
    //Chequeo soluciones sin el elem actual c[i-1]
    if (subset_sum(c, i-1, j)){
        return true;
    }
    //Chequeo soluciones con elem actual c[i-1], se lo resto a j
    if(subset_sum(c,i-1,j-c[i-1])){
        return true;
    }

    //Si llego acá es porque no hubo soluciones
    return false;
}

int main(int argc, char* argv[]){
    // Los dos nums pasados por parámetro los pongo en k y n
    int k = atoi(argv[1]);  //k = num que quiero averiguar si se obtiene
    int n = atoi(argv[2]);  //n = tamaño de conjunto

    vector<int> c(n);       //creo el vector de tamaño n

    for (int i = 0; i < n; i++) {   //para cada lugar del vector creado
        c[i] = atoi(argv[3 + i]);   //agrego los parametros de argv[3] en adelante
    }

    //Esto me imprime las entradas, puedo no ponerlo
    printf("k: %d\nn: %d\nc: {", k, n);
    for (int i = 0; i < n; i++) {
        printf("%d", c[i]);
        if (i < n - 1) printf(", ");
    }
    printf("}\n");

    //acá iría parte de una poda que usó honi "Initial sum of all remaining elements."

    //acá inicializa vector solucion y reserva luego le reserva n lugares

    bool resultado = subset_sum(c,n,k);  //esto devuelve True o False
    printf("El valor de verdad es: %B\n", resultado);
}