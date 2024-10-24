
#include <iostream>
#include <fstream>

using namespace std;


int euclides (int a, int b) {
    if (b == 0) return a;
    else return euclides(b, a % b);
}

bool resuelveCaso() {
    int a, b;
    cin >> a >> b;
    if(a == 0 && b == 0)return false;
    cout << euclides(a, b) << '\n';
   
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
