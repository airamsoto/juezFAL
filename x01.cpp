#include <iostream>
#include <fstream>
#include <vector>
//airam martin soto E37
using namespace std;

/*
 * n = v.size()
 * P{v.size >= 0, picos = 0, valles = 0}
 *  proc calculaPicosYValles (vector<int> & v, int &picos, int&valles)
 * Q{valles = #e (v[e-1] > v[e] < v[e+1]) ^ picos  = #u(v[u-1] < v[u] > v[u+1]}
 *
 * Invariante: 1 <= i <= n -1 ^ valles = #e (v[e-1] > v[e] < v[e+1]) ^ picos  = #u(v[u-1] < v[u] > v[u+1] ^ Vp : prev = v[p-1}]
 *
 *
 * Funcion cota: n - 2 - i
 *
 */

void calculaPicosYValles (vector<int> & v, int &picos, int&valles){
    int prev = v[0];
    for (int i = 1; i < v.size() - 1; ++i) {
        if(prev > v[i] && v[i+1] > v[i]) valles++;
        else if(prev < v[i] && v[i+1] < v[i]) picos++;
        prev = v[i];
    }
}

void resuelveCaso () {
    int n;
    cin >> n;
    vector<int> v;
    int aux;
    for (int i = 0; i < n; ++i) {
        cin >> aux;
        v.push_back(aux);
    }

    int picos = 0, valles = 0;

    calculaPicosYValles(v, picos, valles);

    cout << picos << " " << valles << '\n';



}


int main() {
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}