
#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
//airam martin soto
using namespace std;

int cerosYUnos(const vector<int> &v, int l) {

}


void resuelveCaso() {

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