#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
//airam martin soto E37
using namespace std;

/*
 * {true}
proc equilibrio ( vector <int > v ) dev int p
{−1 ≤ p < v.size() ∧ numUnos(v, p + 1) = numCeros(v, p + 1)
∧∀k : p < k < v.size() : numUnos(v, k + 1) 6= numCeros(v, k + 1)}
donde numUnos(v, j) = #i : 0 ≤ i < j : v[i] = 1 y numCeros(v, j) = #i : 0 ≤ i < j : v[i] = 0.
 */

void equilibrio(vector<int> &v, int &last) {
    int ceros = 0, unos = 0;

    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == 0) ceros++;
        else if (v[i] == 1) unos++;

        if (ceros == unos) last = i;
    }
}

void resuelveCaso() {
    int n, aux;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> aux;
        v.push_back(aux);
    }

    int last = -1;

    equilibrio(v, last);

    cout << last << '\n';


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
}//
// Created by airam on 03/06/2024.
//
