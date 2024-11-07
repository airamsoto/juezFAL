#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int jugando (int n) {
    if(n < 10) {
        if(n %2 == 0) return n +1;
        else return n -1;
    } else {
        int ultuimoDigito = n % 10;
        if(ultuimoDigito % 2 == 0) ultuimoDigito+=1;
        else ultuimoDigito-=1;
        return jugando (n/10) * 10 + ultuimoDigito;
    }
}
    
void resuelveCaso() {
    int n;
    cin >> n;
    cout << jugando(n) << endl;

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
