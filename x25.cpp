

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

/*
 * T(0) c1 si n == 1
 *
 * T(n) 1T(n/2) + k1 si n > 1
 *
 * Costes: por el teorema de la division tenemos una llamada de tamaño la mitad en cada
 * recursion por lo que el coste de la funcion ganador es log n siendo n el numero de
 * elementos que presenta el carton
 */

int bongo (const vector<int>& v, int ini, int fin, int cantado) {
    if(ini == fin) {
        if(ini + cantado == v[fin]) return v[ini];
        else return -1;
    } else {
        int m = (ini + fin)/2;
        if(v[m] >= m + cantado) {
            return bongo (v, ini, m, cantado);
        } else {
            return bongo (v, m+1, fin, cantado);
        }
    }
}


void resuelveCaso() {
    int cantado, carton;
    cin >> carton >> cantado;
    vector<int> v(carton);
    for (int i = 0; i < carton; ++i) {
        cin >> v[i];
    }

    int p = bongo(v, 0, carton-1, cantado);
    if(p == -1) cout << "NO" << '\n';
    else cout << p << '\n';



}


int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int nCasos;
    cin >> nCasos;
    for (int i = 0; i < nCasos; ++i) {
        resuelveCaso();
    }

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);//system("pause");
#endif
    return 0;
}
