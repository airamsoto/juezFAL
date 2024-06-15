#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void repartoMascarillas(vector<int> &necesarias, vector<int> &stock, vector<int> &precios, vector<int> &mascarillasAct,
                        int& precioAct, int &mejorPrecio, int k, vector<int> &sol, int m) {
    if (k == m) {
        bool todasCubiertas = true;
        for (int i = 0; i < necesarias.size(); ++i) {
            if (mascarillasAct[i] < necesarias[i]) {
                todasCubiertas = false;
                break;
            }
        }
        if (todasCubiertas) {
            mejorPrecio = min(mejorPrecio, precioAct);
        }
        return;
    }

    for (int uni = 0; uni < necesarias.size(); ++uni) {
        if (mascarillasAct[uni] < necesarias[uni] && stock[k] > 0) {
            int cantidad_a_comprar = min(stock[k], necesarias[uni] - mascarillasAct[uni]);
            mascarillasAct[uni] += cantidad_a_comprar;
            stock[k] -= cantidad_a_comprar;
            precioAct += cantidad_a_comprar * precios[k];

            if (precioAct < mejorPrecio) {
                repartoMascarillas(necesarias, stock, precios, mascarillasAct, precioAct, mejorPrecio, k + 1, sol, m);
            }

            precioAct -= cantidad_a_comprar * precios[k];
            stock[k] += cantidad_a_comprar;
            mascarillasAct[uni] -= cantidad_a_comprar;
        }
    }

    repartoMascarillas(necesarias, stock, precios, mascarillasAct, precioAct, mejorPrecio, k + 1, sol, m);
}

void resuelveCaso() {
    int universidades, suministradores;
    cin >> universidades >> suministradores;

    vector<int> necesarias(universidades);
    vector<int> stock(suministradores);
    vector<int> precios(suministradores);

    for (int i = 0; i < universidades; ++i) {
        cin >> necesarias[i];
    }
    for (int i = 0; i < suministradores; ++i) {
        cin >> stock[i];
    }
    for (int i = 0; i < suministradores; ++i) {
        cin >> precios[i];
    }

    int precioAct = 0, mejorPrecio = INT_MAX;
    vector<int> mascarillasAct(universidades, 0);
    vector<int> sol(suministradores, -1);

    repartoMascarillas(necesarias, stock, precios, mascarillasAct, precioAct, mejorPrecio, 0, sol, suministradores);

    if (mejorPrecio == INT_MAX) {
        cout << "NO" << '\n';
    } else {
        cout << mejorPrecio << '\n';
    }
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        resuelveCaso();
    }

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
