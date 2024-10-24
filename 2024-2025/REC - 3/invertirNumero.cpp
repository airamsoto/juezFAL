
#include <iostream>
#include <fstream>

using namespace std;



int inverso(int n, int m) {
    if (n < 10 && m == 0) return n;
    else if (n == 0) return m;
    else {
        return inverso(n / 10, m * 10 + (n % 10));
    }
}


bool resuelveCaso() {
    int n;
    cin >> n;
    if(n == 0)return false;
    cout << inverso(n, 0) << '\n';
    return true;
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


   while (resuelveCaso()){}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);

#endif

    return 0;
}
