#include <iostream>
#include <fstream>
#include <vector>
//airam martin soto 
using namespace std;
//TODO FALTA LA POSTCONDICION
/*
 * n = v.size()
 * P{ n >= 1}
 * func lastTime (vector<string> &v, string  pais, int&last)
 * Q{
 *  0 <= e < v.size()
 *  last  = v.size() - e sii v[e] == pais
 * }
 *
 * Invariante: 0<= i<v.size()
 *
 *
 * Funcion cota: n -.i
 *
 */


void lastTime (vector<string> &v, string  pais, int&last){
    for (int i = 0; i < v.size(); ++i) {
        if(v[i] == pais) last = v.size() - i;
    }

}

bool resuelveCaso() {

    int n;
    string pais;
    cin >> n;
    if (n == 0)return false;
    cin >> pais;
    vector<string> v;
    string aux;
    for (int i = 0; i < n; ++i) {
        cin >> aux;
        v.push_back(aux);

    }

    int last = -1;

    lastTime(v, pais, last);
    if(last == -1) cout << "NUNCA" << '\n';
    else cout << last << '\n';





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