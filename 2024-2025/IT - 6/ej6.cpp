#include <iostream>
#include <fstream>
#include <vector>
//airam martin soto 
using namespace std;


void sensor (vector<int> &v, int valorErroneo) {
    int nuevoSize = 0, j = 0;
    for (int i = 0; i < v.size(); ++i) {
        if(v[i] != valorErroneo) {
            nuevoSize++;
            v[j] = v[i];
            j++;
        }

    }
    cout <<  nuevoSize << '\n';
    for (int i = 0; i < nuevoSize; ++i) {
        cout << v[i] << " ";
    }
    cout << '\n';
}

void resuelveCaso() {
    int n, valorIncorrecto;
    cin >> n >> valorIncorrecto;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sensor(v, valorIncorrecto);

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
#endif
    return 0;
}