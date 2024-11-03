#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void numeroDeSuperficies(const vector<int> &v, int l) {
    int contador = 0, actual = 1;
    vector<int> inicios;

    int inicio = -1;
    for (int i = 0; i < v.size() - 1; i++) {
        if (abs(v[i] - v[i + 1]) <= 1) {
            if (actual == 1) inicio = i;
            actual++;
            if (actual >= l) { 
                if (actual == l) { 
                    contador++;
                    inicios.push_back(inicio);
                }
            }
        } else {
            actual = 1;
        }
    }

    cout << contador;
    for (int inicio : inicios) {
        cout << " " << inicio;
    }
    cout << '\n';
}

bool resuelveCaso() {
    int n, l;
    cin >> n >> l;
    if (n == 0 && l == 0) return false;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    numeroDeSuperficies(v, l);
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
