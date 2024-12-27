#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

int elementoMayoritario(const vector <int> &v, int ini, int fin, int n) {
    if (ini == fin - 1) {
        return v[ini];
    } else {
        int mitad = (ini + fin) / 2;
    int izq = elementoMayoritario(v, ini, mitad, n);
    int der = elementoMayoritario(v, mitad, fin, n);
    int resultado = -1;
    if (izq == der) {
        resultado = izq;
    } else {
        int contIzq = 0, contDer = 0;
        for (int i = ini; i < fin; ++i) {
            if (v[i] == izq) {
                contIzq++;
            } else if (v[i] == der) {
                contDer++;
            }
        }
        if (contIzq > n / 2) {
            resultado = izq;
        } else if (contDer > n / 2) {
            resultado = der;
            }
     }
    return resultado;
    }
    
}

void resuelveCaso() {
    int n;
    cin >> n;
    vector <int> v;
    while(n != 0) {
        v.push_back(n);
        cin >> n;
    }
    if(v.size() == 0) {
        cout << "NO" << '\n';
        return;
    }
    sort(v.begin(), v.end());
    int mayoritario = elementoMayoritario(v, 0, v.size(), v.size());
    if (mayoritario == -1) {
        cout << "NO" << '\n';
    } else {
        cout << mayoritario << '\n';
    }

}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int nCasos;
    cin >> nCasos;
    for (int i = 0; i < nCasos; ++i) {
        resuelveCaso();
    }

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}
