#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <numeric>
#include <algorithm>
using namespace std;

//contador y minimo actual
pair <int, int> rio (const vector <int> &v, int ini, int fin) {
    if(ini == fin-1) return {1,v[ini]};
    else {
        int mitad = (ini + fin) /2;
        pair<int, int> izquierda = rio(v, ini, mitad);
        pair <int, int> derecha = rio (v, mitad, fin);
        int contador = 0, minimo;
        if(izquierda.second < derecha.second) {
            contador = izquierda.first;
            minimo = izquierda.second;
        } else if(izquierda.second > derecha.second) {
            contador = derecha.first;
            minimo = derecha.second;
        } else {
            minimo = derecha.second;
            contador = derecha.first + izquierda.first;
        }
        return {contador, minimo};
    }

}


bool resuelveCaso() {
    int n;
    cin >> n;
    if(n == -1) return false;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    cout << rio(v, 0, n).first << '\n';
   
    
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

