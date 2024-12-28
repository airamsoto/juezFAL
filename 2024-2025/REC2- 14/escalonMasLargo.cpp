#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

struct Resultado {
    int longitudMaxima;
    int primeraLongitud;
    int ultimaLongitud;
};

Resultado escalonMasLargo(const vector<int> &v, int ini, int fin) {
    if (ini == fin - 1) {
        return {1, 1, 1};
    } else {
        int mitad = (ini + fin) / 2;
        Resultado izq = escalonMasLargo(v, ini, mitad);
        Resultado der = escalonMasLargo(v, mitad, fin);

        int longitudMaxima = max(izq.longitudMaxima, der.longitudMaxima);
        if (v[mitad - 1] == v[mitad]) {
            int longitudCombinada = izq.ultimaLongitud + der.primeraLongitud;
            longitudMaxima = max(longitudMaxima, longitudCombinada);
        }

        int primeraLongitud = izq.primeraLongitud;
        if (izq.primeraLongitud == (mitad - ini) && v[mitad - 1] == v[mitad]) {
            primeraLongitud += der.primeraLongitud;
        }

        int ultimaLongitud = der.ultimaLongitud;
        if (der.ultimaLongitud == (fin - mitad) && v[mitad - 1] == v[mitad]) {
            ultimaLongitud += izq.ultimaLongitud;
        }

        return {longitudMaxima, primeraLongitud, ultimaLongitud};
    }
}

bool resuelveCaso() {
    int n;
    cin >> n;
    if (n == 0) return false;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    Resultado resultado = escalonMasLargo(v, 0, n);
    cout << resultado.longitudMaxima << '\n';

    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}
