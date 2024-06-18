#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
bool extrano(const vector<int>& numeros, int inicio, int fin) {
    if (inicio == fin - 1) { //CB
        return true;
    }

    int mitad = (inicio + fin) / 2;

    int sumParesPrimeraMitad = 0;
    int prodImparesPrimeraMitad = 1;

    for (int i = inicio; i < mitad; ++i) {
        if (numeros[i] % 2 == 0) {
            sumParesPrimeraMitad += numeros[i];
        }
        else {
            prodImparesPrimeraMitad *= numeros[i];
        }
    }

    int sumImpSegundaMitad = 0;
    int prodParSegundaMitad = 1;
    for (int i = mitad; i < fin; ++i) {
        if (numeros[i] % 2 != 0) {
            sumImpSegundaMitad += numeros[i];
        }
        else {
            prodParSegundaMitad *= numeros[i];
        }
    }

    bool izq = extrano(numeros, inicio, mitad);
    bool der = extrano(numeros, mitad, fin);

    return sumParesPrimeraMitad + prodImparesPrimeraMitad <= prodParSegundaMitad + sumImpSegundaMitad && (izq || der);
}

bool resolver(vector<int> const& v)
//Esta funcion determina si v es extraño
{
    //Invoca aqui a tu funcion recursiva
    return extrano(v, 0, v.size());
}


void resuelveCaso() {
    int n = 0;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];
    if (resolver(v))
        cout << "SI\n";
    else
        cout << "NO\n";
}
int main() {
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int nCasos;
    cin >> nCasos;
    for (int i = 0; i < nCasos; ++i) {
        resuelveCaso();
    }
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
