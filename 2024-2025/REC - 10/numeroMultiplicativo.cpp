#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int digitosMultiplicativosComplementario(int n, int producto, int cuenta) {
    if (n < 10) {
        return (producto == 1) ? cuenta + 1 : cuenta;
    } else {
        
    }
}

int digitosMultiplicativos(int n) {
    if (n < 10) {
        return (n == 1) ? 1 : 0;
    } else {
        return digitosMultiplicativosComplementario(n, 1, 0);
    }
}

void resuelveCaso() {
    int n;
    cin >> n;
    cout << digitosMultiplicativos(n) << endl;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        resuelveCaso();
    }

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}
