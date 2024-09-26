#include <iostream>
#include <fstream>
#include <vector>
//airam martin soto E37
using namespace std;

int iguales (const vector<int>&v, int l) {
    int contador = 0,  dev = 0, prev = v[0];
    for (int i = 0; i < v.size(); ++i) {
        if (prev == v[i]) {
            contador++;
        } else {
            contador = 1;
            prev = v[i];
        }
        if(contador >= l) dev+= contador - l +1;
    }
    return dev;
}


void resuelveCaso() {

    int l, n;
    cin >> l >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    cout << iguales(v, l) << '\n';
}


int main() {
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        resuelveCaso();
    }

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}