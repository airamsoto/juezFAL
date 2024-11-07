#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct tSol {
    bool ok;
    int suma;
    int digitos;
};

tSol segundo(int n) {
    if (n == 0) return {true, 0, 1};
    else {
        tSol sol = segundo(n / 10);
        sol.suma += n % 10;
        if (sol.ok == true && sol.suma % sol.digitos == 0) {
            return {true, sol.suma, sol.digitos + 1};
        }
        return {false, 0, 0};
    }
}

bool resuelveCaso() {
    int n;
    cin >> n;
    if (n == 0) return false;
    tSol resultado = segundo(n);
    cout << (resultado.ok ? "SI" : "NO") << endl;
    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

   while (resuelveCaso()){}
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}
