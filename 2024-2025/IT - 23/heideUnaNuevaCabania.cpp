#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void heide(const vector<int> &v, int l) {
    vector<int> sol;
    int secuenciaMasLarga = 0;
    int numeroLlanuras = 0;

    int contador = 1;
    int maxValorDerecha = v.back();
    bool esLlano = false;

    for (int i = v.size() - 2; i >= 0; --i) {
        if (v[i] == v[i + 1]) {
            contador++;
        } else {
            contador = 1;
        }

        if (contador >= l && v[i] >= maxValorDerecha) {
            if (!esLlano) {
                numeroLlanuras++
                ;
                sol.push_back(i  + contador - 1);
                esLlano = true;
            }
            secuenciaMasLarga = max(secuenciaMasLarga, contador);
        } else {
            esLlano = false;
        }

        maxValorDerecha = max(maxValorDerecha, v[i]);
    }

    cout << secuenciaMasLarga << " " << numeroLlanuras << " ";
    for (int pos : sol) {

        cout << pos << " ";
    }
    cout << '\n';

}

bool resuelveCaso() {
    int n, l;
    cin >> n >> l;
    if(!cin) return false;
    vector<int> v (n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    heide(v, l);

    return true;
}

int main() {
#ifndef DOMJUDGE
    ifstream in("sample.in");
    cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso()) {}

#ifndef DOMJUDGE
    cin.rdbuf(cin.rdbuf());
#endif

    return 0;
}
