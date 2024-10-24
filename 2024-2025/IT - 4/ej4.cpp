#include <iostream>
#include <fstream>
#include <vector>
//airam martin soto 
using namespace std;


bool esApta (const vector<int> &v, int desnivel) {
    int acum = 0, i = 1;
    bool apta = true;
    while (i < v.size() && apta) {
        int prev = v[i-1];
        int act = v[i] - prev;
        if(act > 0) acum+= act;
        else acum = 0;
        if(acum > desnivel) apta = false;
        i++;
    }
    return apta;
}


bool resuelveCaso() {
    int desnivelMaximo, n;
    cin >> desnivelMaximo >> n;
    if (!cin) return false;

    vector<int> v (n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    if(esApta(v, desnivelMaximo)) cout << "APTA\n";
    else cout << "NO APTA\n";



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