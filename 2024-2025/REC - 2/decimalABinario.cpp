
#include <iostream>
#include <fstream>

using namespace std;

string decinalToBinary(long long int n) {
    if (n == 0) return "0";
    if (n == 1) return "1";
    return decinalToBinary(n / 2) + to_string(n % 2);
}



void resuelveCaso() {
    long long int n;
    cin >> n;
   cout << decinalToBinary(n) << '\n';
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


   int n;
   cin >> n;
   for (int i = 0; i < n; i++)
   {
        resuelveCaso();    
   }
   

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);

#endif

    return 0;
}
