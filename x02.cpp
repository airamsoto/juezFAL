#include <iostream>
#include <fstream>
#include <vector>
//airam martin soto E37
using namespace std;

/*
 * n = v.size()
 * P{n >= 2}
 * func esDalton(vector<int> &v) dev bool b
 * Q{
 * b = 0<= e <= n - 1: (Ve (v[e] < v[e+1] || v[e] > v[e+1])
 * }
 *
 * Invariante: b = 0<= e <= n - 1: (Ve (v[e] < v[e+1] || v[e] > v[e+1]) ^ 0 <= i < v.size() -1
 *
 *
 * Funcion cota: n - i -1
 *
 */

bool esDalton(vector<int> &v) {
    bool asciende = true;
    bool descendiente = true;
    int i = 0;
    while (i < v.size() - 1 && (descendiente || asciende)) {
        if (abs(v[i] - v[i + 1]) == 0) return false;

        if (v[i] - v[i + 1] >= 1) asciende = false;

        else if (v[i] - v[i + 1] <= -1) descendiente = false;
        i++;

    }

    return asciende || descendiente;

}


bool resuelveCaso() {

    int n;
    cin >> n;
    if (n == 0)return false;
    vector<int> v;
    int aux;
    for (int i = 0; i < n; ++i) {
        cin >> aux;
        v.push_back(aux);

    }

    if (esDalton(v)) cout << "DALTON" << '\n';
    else cout << "DESCONOCIDOS" << '\n';


    return true;


}


int main() {
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso()) {}

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}