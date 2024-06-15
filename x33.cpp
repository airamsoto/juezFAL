#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void compra(const vector<vector<int>> &matriz, vector<int> &productosPorSuper, int k, vector<int> &sol,
            vector<int> &mejorSol,
            int &precioActual, int &mejorPrecio, int n, const vector<int> &acumuladores, int &minCoste) {

    for (int i = 0; i < n; ++i) {


        sol[k] = matriz[i][k];
        precioActual += matriz[i][k];
        minCoste -= acumuladores[k];
        int estimacion = precioActual + minCoste;

        if ((productosPorSuper[i] < 3 && k == sol.size() - 1) &&
            (mejorPrecio == -1 || precioActual < mejorPrecio)) {
            mejorSol = sol;
            mejorPrecio = precioActual;


        } else if ((mejorPrecio == -1 || estimacion < mejorPrecio) && (k < sol.size() - 1 && productosPorSuper[i] < 3)) {
            productosPorSuper[i]++;
            compra(matriz, productosPorSuper, k + 1, sol, mejorSol, precioActual, mejorPrecio, n, acumuladores,
                   minCoste);
            productosPorSuper[i]--;

        }

        precioActual -= matriz[i][k];
        minCoste += acumuladores[k];
    }

}

void buscaMin(vector<int> &minValores, const vector<vector<int>> &precios, int &minCoste, int i, int j) {
    if (minValores[j] == -1 || precios[i][j] < minValores[j]) {
        if (precios[i][j] < minValores[j]) {
            minCoste -= minValores[j];
        }
        minCoste += precios[i][j];
        minValores[j] = precios[i][j];


    }
}

bool resuelveCaso() {
    int supermercados, productos;
    cin >> supermercados >> productos;
    if (!cin) return false;

    vector<vector<int>> compras(supermercados, vector<int>(productos));
    vector<int> productosPorSuper(supermercados, 0);
    vector<int> sol(productos);
    vector<int> mejorSol(productos);
    int precioActual = 0;
    int mejorPrecio = -1;
    int minCoste = 0;
    vector<int> minValores(productos, -1);

    for (int i = 0; i < supermercados; ++i) {
        for (int j = 0; j < productos; ++j) {
            cin >> compras[i][j];
            buscaMin(minValores, compras, minCoste, i, j);
        }
    }

    vector<int> acumuladores(productos, 0);
    acumuladores[productos - 1] = minValores[productos - 1];
    for (int i = productos - 2; i >= 0; --i) {
        acumuladores[i] = acumuladores[i + 1] + minValores[i];
    }

    compra(compras, productosPorSuper, 0, sol, mejorSol, precioActual, mejorPrecio, supermercados, acumuladores,
           minCoste);

    if (mejorPrecio != -1) cout << mejorPrecio << '\n';
    else cout << "Sin solucion factible" << '\n';

    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    unsigned int numCasos;
    std::cin >> numCasos;

    while (resuelveCaso()) {}

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}
