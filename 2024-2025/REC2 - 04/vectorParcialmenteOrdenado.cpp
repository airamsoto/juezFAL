/*
si el valor
m´aximo de su mitad derecha es mayor o igual que todos los valores de la mitad izquierda y el valor
m´ınimo de su mitad izquierda es menor o igual que todos los valores de su mitad derecha. Adem´as tanto
la mitad izquierda como la derecha cumplen que est´an parcialmente ordenados.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
/*
falla por que : INI : 0FIN : 1
6  1  6  1  
INI : 1FIN : 2
8  1  8  1 
*/
bool estaParcialmenteOrdenado (const vector<int>&v, int &maximo, int&minimo, int ini, int fin) {
    if(ini == fin - 1) {
        maximo = minimo = v[ini];
        return true;
    } else {
        int m = (ini + fin) / 2;
        int maximoIzq, minimoIzq, maximoDer, minimoDer;
        bool izq = estaParcialmenteOrdenado(v, maximoIzq, minimoIzq, ini, m);
        bool der = estaParcialmenteOrdenado(v, maximoDer, minimoDer, m, fin);
        maximo = max(maximoIzq, maximoDer);
        minimo = min(minimoIzq, minimoDer);
        return izq && der && maximoIzq <= maximoDer && minimoIzq <= minimoDer;

    }
}



bool resuelveCaso() {
     int aux;
    vector<int> v;
    while (cin >> aux && aux != 0) {
        v.push_back(aux);
    }

    if (v.empty()) return false;

    int maximo, minimo;
    if (estaParcialmenteOrdenado(v, maximo, minimo, 0, v.size())) {
        cout << "SI\n";
    } else {
        cout << "NO\n";
    }
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

