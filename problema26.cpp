
#include <iostream>
#include <vector>
#include <fstream>  // Agrega la biblioteca para manejo de archivos
using namespace std;

bool esDegradado (const vector<int> &fila, int inicio, int final) {
    if(inicio == final-1) return true;
    int mitad = (final + inicio ) / 2;
    int sumaIzq = 0;
    //cambiar los bucles
    for (int i = inicio; i < mitad; ++i) {
        sumaIzq+=fila[i];
    }
    int sumaDer = 0;
    for (int j = mitad; j < final; ++j) {
        sumaDer+= fila[j];
    }

    if (sumaIzq >= sumaDer) return false;
    return (esDegradado(fila, inicio, mitad) && (esDegradado(fila, mitad, final)));

}

bool esMatrizDegradado(const vector<vector<int>>& matriz, int fila, int n) {
    if (fila == n)
        return true;
    if (!esDegradado(matriz[fila], 0, matriz[fila].size()))
        return false;
    return esMatrizDegradado(matriz, fila + 1, n);
}

bool resuelveCaso() {
    int f, c;
    cin >> f;
    if (!std::cin)
        return false;
    cin >> c;

    vector<vector<int>> matriz(f, vector<int>(c));

    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> matriz[i][j];
        }
    }

    if (esMatrizDegradado(matriz, 0, f)) {
        cout << "SI" << std::endl;
    } else {
        cout << "NO" << std::endl;
    }


    return true;
}

int main() {
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    // Elimina la línea system("pause") para evitar problemas en algunos entornos
#endif

    return 0;
}
