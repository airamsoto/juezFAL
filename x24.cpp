

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


int minimoDelVector (const vector<int>& v, int ini, int fin) {
    if(ini == fin) return v[ini];
    else {
        int m = (ini + fin) / 2;
        if(v[m] < v[ini]) {
            return minimoDelVector(v, m, fin);
        } else return minimoDelVector(v, ini, m);
    }
}
bool resuelveCaso() {

    int n;
    cin >> n;
    if (!cin) return false;

    vector<int> v (n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    cout << minimoDelVector(v, 0, n) << '\n';





    return true;
}


int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    //system("pause");
#endif
    return 0;
}
