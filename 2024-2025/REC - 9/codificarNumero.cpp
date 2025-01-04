#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int mayorDigitoIzquierda(int n) {
    if (n < 10) return n;
    return max(n % 10, mayorDigitoIzquierda(n / 10));
}

int codificarNumero(int n, int pos, int& minDer) {
    if (n == 0) return 0;
    
    int digito = n % 10;
    int nuevoMinDer = minDer;
    if (digito != minDer) {
        nuevoMinDer = min(digito, minDer);
    }
    
    if (pos % 2 == 1) {
        return 3 * digito + codificarNumero(n / 10, pos + 1, nuevoMinDer) + minDer;
    } else {
        return 2 * digito + mayorDigitoIzquierda(n / 10) + codificarNumero(n / 10, pos + 1, nuevoMinDer);
    }
}

void resuelveCaso() {
    int n;
    cin >> n;
    int minDer = 9;
    cout << codificarNumero(n, 0, minDer) << endl;
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
