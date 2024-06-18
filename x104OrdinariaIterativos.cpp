#include <iostream>
#include <fstream>
#include <vector>
//airam martin soto E37
using namespace std;

int iguales (const vector<int> &v, int l) {
    int prev = v[0], contador = 0, r = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == prev) {
            contador++;
            if(contador >= l) {
                r += contador - l + 1;
            }

        } else {
            prev = v[i];
            contador = 1;
            if(contador >= l) {
                r += contador - l + 1;
            }
        }

    }
    return r;
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