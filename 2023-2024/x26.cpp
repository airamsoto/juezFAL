

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int esDegradadoPorFilas (const vector<int>& v, int ini, int fin, bool &es) {
    if (ini == fin) {
        es = true;
        return v[ini];
    } else{
        int m= (ini + fin) /2;
        bool bi, bd;
        int izq = esDegradadoPorFilas(v, ini, m, bi);
        int der = esDegradadoPorFilas(v, m+1, fin, bd);
        es = izq < der && bi && bd;
        return izq + der;
    }
}
bool esDegradado (const vector<vector<int>> &matriz, int ini, int fin) {
    if(ini == fin) {
        return true;
    }
    bool jose;
    esDegradadoPorFilas(matriz[ini], 0, matriz[ini].size()-1, jose);
    if(!jose) return jose;
    return esDegradado(matriz, ini+1, fin);

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
    if(esDegradado(matriz, 0, f)) cout << "SI";
    else cout << "NO";
    cout << '\n';


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
/*
 *
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

 */
