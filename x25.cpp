

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
bool ganador (const vector<int>& v, int cantado, int &ganado, int ini, int fin)  {
    if(ini == fin) {
        ganado = v[ini];
        return cantado+ini == v[ini];
    } else {
        int m = (ini + fin) / 2;
        if(v[m] >= cantado + m) {
            return ganador(v, cantado, ganado, ini, m);
        } else return ganador(v, cantado, ganado, m+1, fin);
    }
}

void resuelveCaso() {
    int cantado, carton;
    cin >> carton >> cantado;
    vector<int> v(carton);
    for (int i = 0; i < carton; ++i) {
        cin >> v[i];
    }
    int ganado;
    if(ganador(v, cantado, ganado, 0, carton-1)) cout << ganado << '\n';
    else cout << "NO" << '\n';


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
