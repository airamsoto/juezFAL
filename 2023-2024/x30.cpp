//TODO torres de colores


/*
 * El coste del algorimto sera el numero de elementos de la solucion,
 * elevado al numero de elementos que pueden optar a estar en cada
 * posicion de la solucion
 * Debemos explicar como sera el vector de solucion
 */
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
//azul = 0, rojo = 1, verde = 2

bool esValida(vector<int> &sol, int k, int color, vector<int> &usados) {
    if (k > 0 && sol[k - 1] == 2 && color == 2) return false;
    if (usados[2] > usados[0]) return false;
    if (usados[1] + sol.size() - 1 - k <= usados[0] + usados[2]) return false;
    return true;

}

void torres(vector<int> &sol, int k, vector<int> &colores, vector<int> &usados, bool &exito) {
    for (int color = 0; color < 3; ++color) {

        if (colores[color] > 0) {
            sol[k] = color;
            colores[color]--;
            usados[color]++;
            if (esValida(sol, k, color, usados)) {
                if (k == sol.size() - 1) {
                    exito = true;
                    for (int i: sol) {
                        if (i == 0) cout << "azul";
                        else if (i == 1) cout << "rojo";
                        else if (i == 2) cout << "verde";
                        cout << " ";
                    }
                    cout << '\n';


                } else {
                    torres(sol, k + 1, colores, usados, exito);
                }
            }
            colores[color]++;
            usados[color]--;

        }


    }
}

bool resuelveCaso() {
    int numero;
    cin >> numero;

    if (numero == 0) return false;


    vector<int> colores(3);
    for (int i = 0; i < 3; ++i) {
        cin >> colores[i];

    }
    vector<int> sol(numero); //vector de soluciones de altura numero
    vector<int> usados(3, 0);
    sol[0] = 1;
    usados[1]++;
    colores[1]--;
    bool jose = false;
    torres(sol, 1, colores, usados, jose);
    if (!jose) cout << "SIN SOLUCION" << '\n';
    cout << '\n';


    return true;
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


    while (resuelveCaso()) {

    }


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);

#endif

    return 0;
}