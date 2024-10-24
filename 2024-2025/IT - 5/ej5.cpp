#include <iostream>
#include <fstream>
#include <vector>
//airam martin soto 
using namespace std;


void secuenciaMasLarga (const vector<int> &v, int n) {
    int contador = 0, inicio, mejorResultado = 0;
    for (int i = 0; i < v.size(); ++i) {
        if(v[i] > n) {
            contador++;
        } else contador = 0;
        if(contador > mejorResultado) {
            inicio =  i - contador + 1;
            mejorResultado = contador;
        }
    }

    cout << inicio << " " << inicio + mejorResultado - 1 << '\n';
}


void resuelveCaso() {
    int elementos, mayor;
    cin >> elementos >> mayor;

    vector<int> v (elementos);
    for (int i = 0; i < v.size(); ++i) {
        cin >> v[i];
    }
    secuenciaMasLarga(v, mayor);



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