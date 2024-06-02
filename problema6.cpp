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
void cerosYUno (const vector<int> &v,int n, int &numCeros, int&numUnos, int& p) {
    for (int i = 0; i < n; ++i) {
        if(v[i] == 0) numCeros++;
        else if(v[i] == 1)  numUnos++;
        if(numCeros == numUnos) p = i;
    }
}
void resuelveCaso() {
    int n;

    cin >> n;
    vector<int> vc(n);

    for (int i = 0; i < n; i++) {
        cin >> vc[i];
    }
    int numUnos = 0, numCeros = 0, posicion = -1;
    cerosYUno(vc, n, numCeros, numUnos, posicion);
    cout << posicion << '\n';

}

int main() {
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
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