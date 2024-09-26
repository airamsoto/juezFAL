#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;
void compraDeLaSemana (const vector<vector<int>> &compra, vector<int>&productosEnSuper, vector<bool>& productos, vector<int>&acum, int n,int k, int &costeActual, int& mejorCoste,vector<int>&sol, vector<int>&mejorSol) {
    for (int super = 0; super < n; ++super) {
        if(productosEnSuper[super] < 3) {
            if(!productos[k]) {
                productos[k] = true;
                productosEnSuper[super]++;
                costeActual+=compra[super][k];
                sol[k] = super;
                if(k == sol.size()-1) {
                    if(costeActual < mejorCoste) {
                        mejorCoste = costeActual;
                        mejorSol = sol;
                    }
                } else if(costeActual + acum[k+1] < mejorCoste){
                    compraDeLaSemana(compra, productosEnSuper, productos, acum, n, k+1, costeActual, mejorCoste, sol, mejorSol);
                }
                productos[k] = false;
                productosEnSuper[super]--;
                costeActual-=compra[super][k];

            }
        }
    }

}

void resuelveCaso(){
    int supermercados, productos;
    cin >> supermercados >> productos;
    vector<int> menores (productos, INT_MAX);
    vector<vector<int>> compra (supermercados, vector<int> (productos));
    for (int i = 0; i < supermercados; ++i) {
        for (int j = 0; j < productos; ++j) {
            cin >> compra[i][j];
            if(menores[j] > compra[i][j]) menores[j] = compra[i][j];

        }
    }
    vector<int> acumuladores(productos, 0);
    acumuladores[productos - 1] = menores[productos - 1];
    for (int i = productos - 2; i >= 0; --i) {
        acumuladores[i] = acumuladores[i + 1] + menores[i];
    }

    vector<int> productosEnSuper (supermercados, 0);
    vector<bool> productosComprados (productos, false);
    int costeActual = 0, costeMejor = INT_MAX;
    vector<int>sol (productos);
    vector<int>mejorSol (productos);

    compraDeLaSemana(compra, productosEnSuper, productosComprados, acumuladores, supermercados, 0, costeActual, costeMejor, sol, mejorSol);
    if(costeMejor == INT_MAX) cout << "Sin solucion factible" << '\n';
    else cout << costeMejor << '\n';
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    unsigned int numCasos;
    std::cin >> numCasos;

    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}
