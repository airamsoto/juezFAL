#include <iostream>
#include <fstream>
#include <vector>
//airam martin soto E37
using namespace std;
/*
 * ESPECIFICACION:
 *
 *
 *
 *
 */
int ultima (const vector<string> &v,int n, string pais) {
    for (int i = n-1; i >= 0; --i) {
        if(v[i] == pais) return n-i;
    }
    return 0;
}
bool resuelveCaso() {
    int n;
    string pais;

    cin >> n >> pais;

    if(n == 0) return false;
    vector<string> vc(n);

    for (int i = 0; i < n; i++) {
        cin >> vc[i];
    }
    int sol = ultima(vc, n, pais);
    if (sol == 0) cout << "NUNCA" << endl;
    else cout << sol << endl;

    return true;
}

int main() {
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    // int numCasos;
    //std::cin >> numCasos;
    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}