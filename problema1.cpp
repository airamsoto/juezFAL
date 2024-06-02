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
void picosYValles (const vector<int> &v,int n, int &picos, int&valles) {
    for (int i = 1; i < n-1; ++i) {
        if (v[i-1] > v[i] && v[i+1] > v[i]) valles++;
        if(v[i-1] < v[i] && v[i+1] < v[i]) picos++;
    }
}
void resuelveCaso() {
    int n;

    cin >> n;
    vector<int> vc(n);

    for (int i = 0; i < n; i++) {
        cin >> vc[i];
    }
    int picos =0, valles = 0;
    picosYValles(vc, n, picos, valles);
    cout << picos << " " << valles << '\n';

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