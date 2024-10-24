#include <iostream>

#include <fstream>
#include <vector>
#include <climits>
using namespace std;
//airam martin soto
bool estaBienDividido (const vector<int> &v, int p) {
    int i = 0, mayorNumero = INT_MIN;

    while (i <= p && i < v.size()) {
        mayorNumero = max(mayorNumero, v[i]);
        i++;
    }
    bool ok = true;
    int j = i;
    while (ok && j < v.size()) {
        if(v[j] <= mayorNumero) ok = false;
        j++;
    }
    return ok;
}




void resuelveCaso() {
    int n, p;
    cin >> n >> p;

    vector <int> v;
    int aux;
    for (int i = 0; i < n; ++i) {
        cin >> aux;
        v.push_back(aux);
    }

    if(estaBienDividido(v, p)) cout << "SI" << '\n';
    else cout << "NO" << '\n';

}


int main() {
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        resuelveCaso();
    }

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}