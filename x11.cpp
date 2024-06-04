#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
//airam martin soto E37
using namespace std;

/*
 *
 * P{
 * v.size() >= 0
 * }
 * func int pistaMasLarga (const vector<int> &v) dev int mejorPista
 *
 * Q{
 *  mejorPista: max (#e : 0<= e< v.size() : para todo u: 0<= u <=e : v[u]<=v[u+1])
 * }
 *
 * invariante: 1<= i < v.size() ^ max (#e : 0<= e< v.size() : para todo u: 0<= u <=e : v[u]<=v[u+1])
 *
 * cota: n - i
 *
 *
 */

int pistaMasLarga (const vector<int> &v) {
    int actual = 1, mejorPista = 1;
    for (int i = 1; i < v.size(); ++i) {
        int prev = v[i-1];
        if(prev - v[i] >= 0) actual++;
        else actual = 1;
        mejorPista = max(actual, mejorPista);

    }
    return mejorPista;



}

void resuelveCaso() {
    int n;
    cin >> n;
    int aux;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        cin >> aux;
        v.push_back(aux);
    }
    if(v.size() == 0) cout<< 0 << '\n';
    else
    cout << pistaMasLarga(v) << '\n';


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
