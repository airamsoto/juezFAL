#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
//airam martin soto E37
using namespace std;

/*
 *
 * P{
 *
 * }
 *
 *
 * Q{
 *
 * }
 *
 * invariante:
 *
 * cota:
 *
 *
 */

//falta el predicado todo pares todosPares(v, p, q

int positivosEnLaIzquierda (const vector<int>& v, int l) {
    int k = 0, positivosIzq = 0, positivosDer = 0, contador = 0;
    for (int i = 0; i < v.size(); ++i) {

        if(k < l/2) {
            if(v[i] > 0) positivosIzq++;

        } else {
            if (v[i] > 0) positivosDer++;
        }
        k++;

        if(k == l) {
            if(positivosIzq >= positivosDer) {
                contador++;

            }
            if(v[i-l+1] > 0) positivosIzq--;
            if(v[i - (k/2) +1] > 0) {
                positivosIzq++;
                positivosDer--;
            }
            k--;
        }
    }
    return contador;

}

bool resuelveCaso() {
    int n, l;
    cin >> n;
    if(n == 0) return false;
   cin >> l;
    vector<int> v (n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }



    cout << positivosEnLaIzquierda(v, l) << '\n';
    return true;



}


int main() {
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while(resuelveCaso()){}

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
   // system("pause");
#endif
    return 0;
}
