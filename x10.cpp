#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
//airam martin soto E37
using namespace std;

/*
 *
 * P{
 * acum = 0, fin = 0, v.size() > 0
 * }
 * proc void secuenciasMasLarga (const vector<int> &v, int altura, int& acum, int&fin)
 * Q{
 *  0<= acum < v.size() ^ 0<=mejorAcum<=fin ^ para todo e: 0<= e< v.size() : Existe u: v[u] > altura
 * }
 *
 * invariante: 0 <= i < v.size() ^ 0<= acum < v.size() ^ 0<=mejorAcum<=fin para todo e: 0<= e< v.size() : Existe u: v[u] > altura
 *  cota: n - i
 *
 */

void secuenciasMasLarga (const vector<int> &v, int altura, int& acum, int&fin) {
    int mejorAcum = 0;
    for (int i = 0; i < v.size(); ++i) {
        if(v[i] > altura) {
            acum++;
            if(acum > mejorAcum) {
                fin = i;
                mejorAcum = acum;
            }
        } else {
            acum = 0;
        }
    }
    acum = mejorAcum;




}

void resuelveCaso() {
    int n, altura;
    cin >> n >> altura;
    int aux;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        cin >> aux;
        v.push_back(aux);
    }

    int ini = 0, fin = 0;

    secuenciasMasLarga(v, altura, ini, fin);
    int inicio = fin - ini + 1;

    cout << inicio << " " << fin << '\n';



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
