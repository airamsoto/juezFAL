#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


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

int presoFugado (vector <char> const&vc, char ini, char fin, int inicio, int final) {
    if(inicio == final-1) {
        if (vc[inicio] -1 == ini) return ini;
        else return fin;
    }
  int medio = (final + inicio) / 2;
  char medioChar = (ini + fin) /2;
  if(vc[medio] > medioChar) {
      return presoFugado(vc, ini, medioChar, inicio, medio);
  } else {
      return presoFugado(vc, medioChar, fin, medio, final);
  }




}



bool resuelveCaso() {
    char ini, fin;

    cin >> ini >> fin;

    int num = fin - ini;

    vector<char> vc(num);
    for (int i = 0; i < num; i++) {
        cin >> vc[i];
    }

    char p = presoFugado(vc, ini, fin, 0, vc.size());
    cout << p << endl;

    return true;
}

int main() {
    // Ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; i++) {
        resuelveCaso();
    }

    // Restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}
//
// Created by Airam Martin Soto on 11/12/23.
//
