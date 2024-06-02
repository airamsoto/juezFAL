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
bool esPastoso (const vector<int> &v,int n, int &pos) {
    int suma = 0, pasto = v[0];
    pos = 0;
    int i = 1;
    while (i < n) {
        suma += v[i];
        if(suma == pasto && i == n-1 ) {
            return true;
        } else if(suma > pasto) {
            i = pos+1;
            pos++;
            suma = 0;
            pasto = v[pos];
        }
        i++;
    }
    return false;
}
void resuelveCaso() {
    int n;

    cin >> n;
    vector<int> vc(n);

    for (int i = 0; i < n; i++) {
        cin >> vc[i];
    }
    int pos = 0;
    if (esPastoso(vc, n , pos))  cout << "SI" << " "  << pos << '\n';
    else cout << "NO" << '\n';




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