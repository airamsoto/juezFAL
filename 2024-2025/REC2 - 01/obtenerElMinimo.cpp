#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


//TODO DEBERIA DAR CORRECT, PENDIENTE DE SUBIR AL JUEZ
int minimo (const vector<int> &v, int ini, int fin) {
    if (ini == fin-1 ) return v[ini];
    else {
        int m  = (ini + fin) / 2;
        if(v[m] >= v[ini]) {
            return minimo (v, ini, m);
        } else return minimo (v, m, fin);
    }
}

bool resuelveCaso() {
    int n;
    cin >> n;
    if(!cin) return false;
    vector<int> v (n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << minimo (v, 0, n) << '\n';
    return true;
    

}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("sample.in");  //o cambia el nombre por el fichero que te descargues
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    while (resuelveCaso()) {}
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
   
#endif

    return 0;
}

