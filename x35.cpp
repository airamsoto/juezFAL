

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


pair<int, bool> esCaucasico (const vector<int> &v, int ini, int fin)  {
    if(ini == fin) {
        int n = 0;
        if(v[ini] % 2 == 0) n = 1;
        return {n, true};
    } else {
        int m = (ini + fin) / 2;
        auto [paresIzq, caucasicoIzq] = esCaucasico(v, ini, m);
        auto[paresDer, caucasicoDer] = esCaucasico(v, m+1, fin);

        return {paresDer + paresIzq, caucasicoDer && caucasicoIzq && abs(paresIzq-paresDer) <= 2 };
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
    bool jose = esCaucasico(v, 0, n-1).second;
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
