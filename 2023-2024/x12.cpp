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
 * func int segmentoDeConsecutivos (const vector<int> &v) dev mayor
 *
 * Q{
 *  mayor = max (#e: 0<= e <v.size(): para todo U 0<= u <= e : abs(v[u] - v[u+1]) == 1)
 * }
 *
 * invariante: 0<= i < v.size() - 1 ^ mayor = max (#e: 0<= e <v.size(): para todo U 0<= u <= e : abs(v[u] - v[u+1]) == 1)
 *
 * cota: n - 1 - i
 *
 *
 */

int segmentoDeConsecutivos (const vector<int> &v) {
   int actual = 1, mayor = 1;
    for (int i = 0; i < v.size() - 1; ++i) {
        int next = v[i+1];
        if(abs(v[i] - next) == 1) actual++;
        else actual = 1;
        mayor = max(actual, mayor);
    }
    return mayor;



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
    else cout << segmentoDeConsecutivos(v) << '\n';



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
