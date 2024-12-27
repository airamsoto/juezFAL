#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <numeric>
#include <algorithm>
using namespace std;

bool esDisperso (const vector <int> &v, int ini, int fin, int k) {
    if(ini == fin-1) {
        return true;
    } else if (ini == fin -2) {
        return abs(v[ini] - v[fin-1]) >= k;
    }
    else {
        int mitad = (ini + fin) / 2;
        bool disperso = abs(v[ini] - v[mitad-1]) >= k && abs(v[mitad] - v[fin-1]) >= k;
        return disperso && esDisperso(v, ini, mitad, k) && esDisperso (v, mitad, fin, k);
    }

}


bool resuelveCaso() {
    int n, k;
    cin >> n >> k;
    if (!cin) return false;

    vector <int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    if(esDisperso(v, 0, n, k)) cout << "SI\n";
    else cout << "NO\n";
    
    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("sample.in");  //o cambia el nombre por el fichero que te descargues
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    while (resuelveCaso()){}
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
   
#endif

    return 0;
}

