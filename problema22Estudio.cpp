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

int minimo(const vector<int> &vc, int inicio, int final) {
    if (inicio >= final -1) {
        if(vc[inicio] > vc[final]) return vc[final];
        return vc[inicio];
    }
    int medio = (final + inicio) / 2;
    if (vc[medio] > vc[medio+1]) {
        return minimo(vc, medio+1, final);
    } else {
        return minimo(vc, inicio, medio);
    }
}





bool resuelveCaso() {
    int f;
    cin >> f;
    if (!cin)
        return false;

    vector<int> vc (f);
    for (int i = 0; i < f; ++i) {
        cin >> vc[i];
    }

    cout << minimo(vc, 0, f-1) << endl;



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
