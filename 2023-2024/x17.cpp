
#include <iostream>
#include <fstream>

using namespace std;

int complementario(int n) {
    if (n < 10) return 9 - n;
    else {
        int complementarioSinUnidades = complementario(n / 10);
        int complementarioConUnidades = 9 - n % 10;
        return complementarioSinUnidades * 10 + complementarioConUnidades;
    }
}

int inverso(int n, int m) {
    if (n < 10 && m == 0) return 9 - n;
    else if (n == 0) return m;
    else {
        return inverso(n / 10, m * 10 + (9 - n % 10));
    }
}

void resuelveCaso() {
    int n;
    cin >> n;
    cout << complementario(n) << ' ' << inverso(n, 0) << '\n';
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


    unsigned int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);

#endif

    return 0;
}
