

#include <iostream>

#include <fstream>
using namespace std;

bool esSumDivisible (int n) {
    if(n < 10) return true;
    else if (n < 100) return (n % 10 + (n%10)%10) % 2 == 0;
    else {
        return esSumDivisible(n/10);
    }
}

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    int n;
    cin >> n;
    if (n == 0) return false;

    cout << esSumDivisible(n) << '\n';


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
