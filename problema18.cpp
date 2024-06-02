#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

bool esSumDivisible(int numero, int n = 0, int suma = 0) {
    if (numero == 0) {
        // Verifica si la suma es divisible por el número de dígitos
        return suma % n == 0;
    }

    int digito = numero % 10;

    // Si el número es igual a 0, estamos en la primera iteración
    // y calculamos la cantidad de dígitos del número
    if (n == 0) {
        n = 1 + static_cast<int>(log10(numero));
    }

    // Suma el dígito actual
    suma += digito;

    // Llama recursivamente con el número sin el último dígito
    return esSumDivisible(numero / 10, n, suma);
}

bool resuelveCaso() {
    int num;
    cin >> num;

    if (num == 0) return false;

    // Verifica si el número es "sumdivisible"
    if (esSumDivisible(num)) {
        cout << "SI" << endl;
    } else {
        cout << "NO" << endl;
    }

    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif

    return 0;
}
