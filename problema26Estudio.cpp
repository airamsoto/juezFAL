/*
 *
 * sea n = vc.size();
 *
 *                      k_0 si 0 <= n < 1
 *
 * recurrencia = T(n)
 *
 *                      1*(T(n/2) * k1 * 2^0 si n > 2
 * coste = Por el teorema de la division, como  1 = 2^0 -> el coste es de n^0 * log n, es decir 0=log n
 * Obtenemos esa recurrenica debido a que cada vez que hay recursion, n pasa a ser n/2 y como solo tenemos una llamada recursiva
 * pues tenemos que a = 1
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

pair <bool, int> esDesgradado (const vector<int> &matriz, int inicioFila, int finalFila) {
    if(inicioFila == finalFila-1) {
        return {true, matriz[inicioFila]};
    } else {
        int medio = (finalFila+inicioFila)/2;


        pair<bool, int> ladoIzq = esDesgradado(matriz, inicioFila, medio);
        cout << ladoIzq.second << endl;



        pair<bool, int> ladoDer = esDesgradado(matriz, medio, finalFila);
        cout << ladoDer.second << endl;


        return {ladoIzq.first && ladoDer.first && ladoIzq.second<ladoDer.second, ladoIzq.second+ladoDer.second};
    }
}


// n numero de filas qu ehay
// fila numero de elementos en cada fila
bool esMatrizDegradado(const vector<vector<int>>& matriz, int fila, int n) {
    if (fila == n)
        return true;

    if (!esDesgradado(matriz[fila], 0, matriz[fila].size()).first)
        return false;
    return esMatrizDegradado(matriz, fila + 1, n);
}





bool resuelveCaso() {
    int f;
    cin >> f;
    if (!cin)
        return false;
    int c;
    cin >> c;
    vector<vector<int>> vc (f, vector<int>(c));
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> vc[i][j];
        }
    }
    if(esMatrizDegradado(vc, 0, f)) cout << "SI";
    else cout << "NO";
    cout << endl;


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
