#include <iostream>
#include <fstream>
#include <vector>
//airam martin soto E37
using namespace std;

int calculaMinimo(vector<int>& v, int ini, int numeros, int indice) {
    if (indice == numeros) {
        return ini;
    }
    if (ini == v[indice]) {
        ini++;
        return calculaMinimo(v, ini, numeros, indice + 1);
    } else {
        return ini;
    }
}

void resuelveCaso() {
    int numeros, ini;

    cin >> numeros >> ini;
    vector<int> vc(numeros);

    for (int i = 0; i < numeros; i++) {
        cin >> vc[i];
    }

    cout << calculaMinimo(vc, ini, numeros, 0) << endl;
}

int main() {
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}