//TODO FUNCIONARIOS SIN ESTIMACION


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
void funcionarios (const vector<vector<int>> &datos, vector<bool> &marcasPuestos, vector<bool> &marcasTrabajadores, int&mejorTiempo, int&tiempoActual, int k, int n, vector<int>&sol, vector<int>&mejorSol) {
    for (int i = 0; i < n; ++i) {
        if(!marcasPuestos[i]) {
            tiempoActual+=datos[k][i];
            marcasTrabajadores[k] = true;
            marcasPuestos[i] = true;
            sol[i] = k;
            if(k == sol.size()-1) {
                if(tiempoActual < mejorTiempo) {
                    mejorTiempo = tiempoActual;
                    mejorSol = sol;
                }
            } else {
                funcionarios(datos, marcasPuestos, marcasTrabajadores, mejorTiempo, tiempoActual, k+1, n, sol, mejorSol);
            }


            tiempoActual-=datos[k][i];
            marcasTrabajadores[k] = false;
            marcasPuestos[i] = false;

        }

    }
}
bool resuelveCaso() {
    int n;
    cin >> n;
    if (n == 0)return false;
    vector<vector<int>> datos (n, vector<int> (n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> datos[i][j];
        }
    }



    vector<bool> marcasPuestos (n, false);
    vector<bool> marcasTrabajadores (n, false);
    int mejorTiempo = INT_MAX, tiempoActual = 0;
    vector<int> sol (n);
    vector<int> mejorSol (n);
    funcionarios(datos, marcasPuestos, marcasTrabajadores, mejorTiempo, tiempoActual, 0, n, sol, mejorSol);
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