#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
//airam martin soto E37
using namespace std;

/*
 * n = v.size()
 * P{suma = 0, numero = 0, v.size() >= 0}
 * proc encuestas(vector<int>& v, long long int&suma, int& numero)
 * Q{contador = n - #e, suma = sumatorio Vu (0<u<=n-e) : v[u]}
 *
 * invariante: 1<=i<v.size(), contador = n - #e, suma = sumatorio Vu (0<u<=n-e) : v[u]
 * e : 0 <= n ^ minimo
 * cota = n - i
 */

bool esPastoso(vector<int> &v, int& pos) {
  //TODO NO ME SALE
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
    int pos = 0;
    if (esPastoso(v, pos )) {
        cout << "SI " << pos << '\n';
    } else cout << "NO" << '\n';


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
