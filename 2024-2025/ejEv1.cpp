/**
 * Escribid el nombre y usuario del juez los miembros de la pareja:
 * Nombre y usuario: Jorge Calvo Fernandez FAL-E07
 * Nombre y usuario: Airam Martin Soto E44
 *
 * Explica brevemente el algoritmo:
 * El algoritmo recorre el mapa del terreno, busca un segmento de valores iguales que sea mayor o igual al numero de castores y que ademas el siguiente valor sea mayor 
 * que los valores del segmento. En caso de que se cumplan esas condiciones, devolvemos true.
 *
 *
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// No olvides escribir la especificacion y justificar adecuadamente el coste
/*
* El coste del algoritmo en el caso peor es lineal 0(n) siendo n la longitud del terreno, debido a que recorre todos los elementos del vector hasta encontrar una solucion
y realiza operaciones de coste constante con ellos.
 
 N = longitud del terreno, c = numero de castores
 Precondicion {1<= N <= 10^8, 1<= c <= N}
 esApta(const vector<int>& v, const int c) dev bool b
 Postcondicion {b = true sii Existe [p, q) siendo q - p = c &&  llano_acotado (w, p, q)}
 

 Predicado:
 llano_acotado(w,p,q) {b = true sii Pt. k perteneciente [p,q) -> v[p] == v[p+1] && v[q] > v[p]
                      b = false en otro caso}

Funcion de cota = n - i - 1 siendo n los elementos del vector del mapa de terreno

Invariante:
n = elementos del vector del mapa de terreno
1<= i <= n-1 
1<= llano <= n
 
 */


// Implementa la función pedida

bool llano_acotado(int w, int p, int q) {
    return true;
}

bool esApta(const vector<int>& v, const int c) {

    int llano = 1;

    for (int i = 1; i < v.size(); i++)
    {
        if (llano >= c && v[i] > v[i - 1])
        {
            return true;
        }
        else
        {
            if (v[i] == v[i - 1])
                llano++;
            else
                llano = 1;
        }
    }
    return false;
}


bool resuelveCaso() {
    // leer los datos de la entrada
    int N, C; //número de datos, número de castores
    cin >> N >> C;
    if (N == 0 && C == 0)
        return false;
    vector<int> valores(N);
    for (int i = 0; i < N; ++i) {
        int e;  cin >> e;
        valores[i] = e;
    }

    //Llama a tu función

    if (esApta(valores, C)) cout << "SI\n";
    else cout << "NO\n";

    // escribe el resultado


    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("1.in"); //o cambia el nombre por el fichero que te descargues
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}