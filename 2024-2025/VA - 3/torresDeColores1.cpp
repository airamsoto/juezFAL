#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

void torresDeColores (const vector <string> & colores, vector <bool> & usados, int alturaTorres, int k, vector <string> &sol) {
    for (int i = 0; i < colores.size(); i++) {
            sol[k] = colores[i];
            if(k == sol.size() - 1) {
                for (int i = 0; i < sol.size(); i++)
                {
                    cout << sol[i] << " ";
                }
                cout << '\n';
                

            } else torresDeColores (colores, usados, alturaTorres, k +1, sol);
    }
}

bool resuelveCaso() {

    int alturaTorres;
    cin >> alturaTorres;
    if (alturaTorres == 0) return false;
    vector <string> colores (3);
    colores[0] = "azul";
    colores[1] = "rojo";
    colores[2] = "verde";
    vector <bool> usados (3, false);
    vector <string> sol (alturaTorres);
    torresDeColores (colores, usados, alturaTorres, 0, sol);
    cout << '\n';
    return true;

}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("sample.in");  //o cambia el nombre por el fichero que te descargues
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    while (resuelveCaso()) {}
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
   
#endif

    return 0;
}

