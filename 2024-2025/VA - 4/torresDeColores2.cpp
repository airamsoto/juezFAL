
#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

/*
No le gusta el color verde, asi que nunca coloca dos piezas verdes juntas
mientras se va construyendo la torre. Adem´as, como el color rojo es su favorito, las torres que construye
siempre tienen en la parte inferior una pieza roja.

*/

bool esValida (const vector<string> &sol, int k, string color) {
    if(k == 0) return color == "rojo";
    if(sol[k-1] == "verde" && color == "verde") return false;
    return true;
}

void torresDeColores2 (const vector <string> & colores, int alturaTorres, int k, vector <string> &sol) {
    for (int i = 0; i < colores.size(); i++) {
        if(esValida (sol, k, colores[i])) {
            sol[k] = colores[i];
            if(k == sol.size() - 1) {
                for (int i = 0; i < sol.size(); i++)
                {
                    cout << sol[i] << " ";
                }
                cout << '\n';
                

            } else torresDeColores2 (colores, alturaTorres, k +1, sol);
        }
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
    vector <string> sol (alturaTorres);
    torresDeColores2 (colores, alturaTorres, 0, sol);
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

