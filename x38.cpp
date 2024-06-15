

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int minimo (const vector<int>& v, int ini, int fin, int primero) {
    if(ini == fin) {
        if (v[ini] > primero + ini) return primero + ini;
        else return v[ini] + 1;

    } else {
        int m = (ini + fin) / 2;
        if(primero + m < v[m]) {
            return minimo(v, ini, m, primero);
        } else return minimo(v, m+1, fin, primero);
    }
}





void resuelveCaso() {
    int n, ini;

    cin >> n >> ini;
    vector<int> v (n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    if(n == 0) cout << ini << '\n';
    else
    cout << minimo (v, 0, n-1, ini) << '\n';



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
