#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
//airam martin soto 
using namespace std;

//TODO PRECONDICION POSTCONDICION Y CAMBIAR A FUNCION EXTERNA QUE DEVUELVA UN VECTOR

void resuelveCaso() {
    int ini, fin, n;
    cin >> ini >> fin;
    n = (fin - ini) + 1;
    vector<int> v (n);
    for (int i = 0; i < v.size(); ++i) {
        cin >> v[i];
    }
    int anio = ini;
    int maximo = INT_MIN;
    for (int i = 0; i < n; ++i) {
        if(v[i] >  maximo) {
            if(maximo != INT_MIN)
            cout << anio << " ";
            maximo = max (maximo, v[i]);
        }
        anio++;
    }





cout << '\n';
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