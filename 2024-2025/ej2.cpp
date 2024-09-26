#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
//airam martin soto
using namespace std;

/*
 * n = numero de elementos de entrada
 * P}
 *
 * Q {{Ve (0<1<=n) : maximo = max(v[e], contador = #e }
 *
 * Invariante: 0<= contador <= n
 *
 *
 * Funcion cota:
 *
 */

void calculaMaximo (int &contador, int&maximo) {
    int aux;
    cin >> aux;
    while (aux != 0) {
        if(aux > maximo) {
            maximo = aux;
            contador = 1;
        } else if(aux == maximo) contador++;

        cin >> aux;
    }
}


void resuelveCaso () {
    int contador = 0, maximo = INT_MIN;
    calculaMaximo(contador, maximo);
    cout << maximo << " " << contador << '\n';
}


int main() {
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}