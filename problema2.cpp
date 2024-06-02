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
bool esDalton (const vector<int> &v,int n) {
    //bool exit = false;
    int i = 0;
    bool crece = true, decrece = true;
    while (i < n-1 && (crece || decrece)) {
        if(v[i]-v[i+1] >=1 ) crece = false;
        if (v[i]-v[i+1] <= -1) decrece= false;
        if(abs (v[i] - v[i+1]) == 0) return false;
        i++;
    }
    return crece || decrece;
}
bool resuelveCaso() {
    int n;

    cin >> n;
    if(n == 0) return false;
    vector<int> vc(n);

    for (int i = 0; i < n; i++) {
        cin >> vc[i];
    }

    if(esDalton(vc, n)) cout << "DALTON"  << '\n';
    else  cout << "DESCONOCIDOS"  << '\n';
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