#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <numeric>
#include <algorithm>
using namespace std;

struct tSol {
    int contador;
    bool esCaucasico;
};

tSol esCaucasico (vector<int> const& v, int ini, int fin) {
    if (ini == fin -1) {
        if(v[ini] % 2 == 0) return {1, true};
        else return {0, true};
    }
    else {
        int mitad = (ini + fin) / 2;
        tSol izq = esCaucasico (v, ini, mitad);
        tSol der = esCaucasico (v, mitad, fin);

        return {izq.contador + der.contador, izq.esCaucasico && der.esCaucasico && abs(izq.contador - der.contador) <= 2};

    }
}
   



bool resuelveCaso() {
    int n;
    cin >> n;
    if(n == 0) return false;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    tSol sol = esCaucasico (v, 0, n);
    if(sol.esCaucasico) cout << "SI\n";
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

