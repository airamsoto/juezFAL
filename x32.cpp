//TODO FUNCIONARIOS CON ESTIMACION


/*
 * El coste del algorimto sera el numero de elementos de la solucion,
 * elevado al numero de elementos que pueden optar a estar en cada
 * posicion de la solucion
 * Debemos explicar como sera el vector de solucion
 */
#include <iostream>
#include <vector>
#include <fstream>
#include <climits>

using namespace std;

void funcionarios(const vector<vector<int>> &trabajadores, int k, int n, vector<int> &sol, vector<int> &mejorSol,
                  vector<bool> &trabajosUsados, int& mejorTiempo, int &tiempoActual, vector<int>&acumuladores) {
    for (int trabajo = 0; trabajo < n; ++trabajo) {
        if(!trabajosUsados[trabajo]) {
            sol[k] = trabajo;
            trabajosUsados[trabajo] = true;
            tiempoActual += trabajadores[k][trabajo];
            int valorEsperado;
            if(k + 1 < n ) valorEsperado=  tiempoActual + acumuladores[k+1];
            else valorEsperado = tiempoActual;
            if(valorEsperado < mejorTiempo) {
                if(k == n -1) {
                    if(tiempoActual < mejorTiempo) {
                        mejorSol = sol;
                        mejorTiempo = tiempoActual;
                    }
                } else { //todo la estiamcion deberia de ponerse aqui para verlo mas claro
                    funcionarios(trabajadores, k + 1, n, sol, mejorSol, trabajosUsados, mejorTiempo, tiempoActual, acumuladores);

                }

            }

            trabajosUsados[trabajo] = false;
            tiempoActual -= trabajadores[k][trabajo];
        }

    }
}

bool resuelveCaso() {
    int numeroTrabajadores;
    cin >> numeroTrabajadores;

    if (numeroTrabajadores == 0) return false;
    vector<int> mejoresValores (numeroTrabajadores, INT_MAX);
    vector<vector<int>> trabajadores(numeroTrabajadores, vector<int>(numeroTrabajadores));

    for (int i = 0; i < numeroTrabajadores; ++i) {
        for (int j = 0; j < numeroTrabajadores; ++j) {
            cin >> trabajadores[i][j];
            int aux = trabajadores[i][j];
            if(aux < mejoresValores[i]) {
                mejoresValores[i] = aux;
            }
        }
    }

    vector<int> acumuladores(numeroTrabajadores, 0);
    acumuladores[numeroTrabajadores - 1] = mejoresValores[numeroTrabajadores - 1];

    for (int i = numeroTrabajadores - 2; i >= 0; --i) {
        acumuladores[i] = acumuladores[i + 1] + mejoresValores[i];
    }

    vector<bool> trabajosUsados(numeroTrabajadores, false);
    vector<int> sol (numeroTrabajadores);
    vector<int> mejorSol(numeroTrabajadores);


    int tiempoAct = 0;
    int mejorTiempo = INT_MAX;

    funcionarios(trabajadores, 0, numeroTrabajadores, sol, mejorSol, trabajosUsados, mejorTiempo, tiempoAct, acumuladores);
    cout << mejorTiempo << '\n';




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