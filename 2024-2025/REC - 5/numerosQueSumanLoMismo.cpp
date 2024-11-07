#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int sumaDigitosNoFinal(int n) {
    if (n == 0)
        return 0;
    return (n % 10) + sumaDigitosNoFinal(n / 10);
}
    
void resuelveCaso() {
    int numElementos, numeroBase;
    cin >> numElementos >> numeroBase;

    int sumaNumeroBase = sumaDigitosNoFinal(numeroBase);


    vector<int> numeros(numElementos);
    for (int i = 0; i < numElementos; i++) {
        cin >> numeros[i];
    }
    bool encontrado = false;
    for (int num : numeros) {
        if (sumaDigitosNoFinal(num) == sumaNumeroBase) {
            if (encontrado) {
                cout << " ";
            }
            cout << num;
            encontrado = true;
        }
    }
    cout << endl;

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
