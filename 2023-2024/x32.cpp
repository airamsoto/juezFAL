
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
void funcionarios (const vector<vector<int>> &datos, vector<bool> &marcasPuestos, vector<bool> &marcasTrabajadores, vector<int>&acumuladores, int&mejorTiempo, int&tiempoActual, int k, int n, vector<int>&sol, vector<int>&mejorSol) {
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
            } else if(tiempoActual + acumuladores[k+1] < mejorTiempo){
                funcionarios(datos, marcasPuestos, marcasTrabajadores, acumuladores, mejorTiempo, tiempoActual, k+1, n, sol, mejorSol);
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
    vector<int> mejoresTiempos (n, INT_MAX);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> datos[i][j];
            if(mejoresTiempos[i] > datos[i][j]) mejoresTiempos[i] = datos[i][j];
        }
    }
    vector<int> acumulados (n);
    acumulados[acumulados.size()-1] = mejoresTiempos[mejoresTiempos.size()-1];
    for (int i = mejoresTiempos.size()-2; i>=0; --i) {
        acumulados[i] = acumulados[i+1] + mejoresTiempos[i];

    }


    vector<bool> marcasPuestos (n, false);
    vector<bool> marcasTrabajadores (n, false);
    int mejorTiempo = INT_MAX, tiempoActual = 0;
    vector<int> sol (n);
    vector<int> mejorSol (n);
    funcionarios(datos, marcasPuestos, marcasTrabajadores, acumulados, mejorTiempo, tiempoActual, 0, n, sol, mejorSol);
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