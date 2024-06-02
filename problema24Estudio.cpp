/*
 *
 * sea n = vc.size();
 *
 *                          k_0 si 0 <= n < 2
 *
 * recurrencia = T(n)
 *                          1*T(n/2) + k1*n^0
 *
 * coste = por el teorema de la division, como n = n/2 despues de cada interaccion, y tenemos que a = 1 = b^k = 1,
 * ya que solo tenemos una llamada recurisva por iteraccion y b^^ = 1 porque solo tenemos acciones constantes pues
 * el coste del programa para n = vc.size() es log n
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
    if (vc[medio] > vc[inicio]) {
        return minimo(vc, inicio, medio);
    } else {
        return minimo(vc, medio, final);
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
