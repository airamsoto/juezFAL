

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool esCaucasico (const vector<int>& v, int ini, int fin, int& numerosPares){
    if(ini == fin) {
        if(v[ini] % 2 == 0) numerosPares++;
        return true;
    } else {
        int m = (ini + fin) / 2;
        int izq =0, der = 0;
        bool caucasicoIzq = esCaucasico(v, ini, m, izq);
        bool caucasicoDer = esCaucasico(v, m+1, fin, der);
        numerosPares += izq + der;
        return caucasicoIzq && caucasicoDer && abs(izq-der)<=2;
    }

}


bool resuelveCaso() {

    int n;
    cin >> n;
    if (n == 0) return false;

    vector<int> v (n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int p = 0;
    bool jose = esCaucasico(v, 0, n-1, p);
    if(jose) cout << "SI" << '\n';
    else cout << "NO" << '\n';

    return true;
}


int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    //system("pause");
#endif
    return 0;
}
