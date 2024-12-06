#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

void compraDeLaSemana (const vector<vector<int>> &datos, vector <int> &productosPorSupermercado,vector<int> &sol, int n, int k, int& costeActual, int& mejorCoste, vector <int> &mejorSol, const vector <int> &baratos) {
    for (int supermercado = 0; supermercado < n; supermercado++)
    {
        if(productosPorSupermercado[supermercado] < 3) {
            sol[k] = datos[supermercado][k];
            productosPorSupermercado[supermercado]++;
            costeActual+=datos[supermercado][k];
        
            if(k == sol.size()-1) {
                if(costeActual < mejorCoste) {
                    mejorSol = sol;
                    mejorCoste = costeActual;
                }

            } else if (costeActual + baratos[k+1] < mejorCoste) compraDeLaSemana(datos, productosPorSupermercado, sol, n, k +1, costeActual, mejorCoste, mejorSol, baratos);
            productosPorSupermercado[supermercado]--;
            costeActual-=datos[supermercado][k];
        }
    }
    

}




void resuelveCaso() {
    int supermercados, productos; //n supermercados y m productos
    //no puede comprar mas de 3 productos en cada supermercado
    cin >> supermercados >> productos;
    vector<vector<int>> datos (supermercados, vector<int> (productos));
    vector <int> productosPorSupermercado (supermercados, 0);
    vector<int> sol (productos, 0); //para almacenar el precio de cada producto
    vector<int> mejorSol (productos, 0);
    vector <int> baratos (productos, INT_MAX);
    for (int i = 0; i < supermercados; i++) {
        for (int j = 0; j < productos; j++) {
            cin >> datos[i][j];
            baratos[j] = min (baratos[j], datos[i][j]);
        }
        
    }
    for (int i = productos - 2; i >= 0; i--) {
        baratos[i] += baratos[i+1];
    }
    int costeActual = 0, mejorCoste = INT_MAX;

    compraDeLaSemana(datos, productosPorSupermercado, sol, supermercados, 0, costeActual, mejorCoste, mejorSol, baratos);
    if(mejorCoste == INT_MAX) cout << "Sin solucion factible\n";
    else cout << mejorCoste << '\n';

}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int nCasos;
    cin >> nCasos;
    for (int i = 0; i < nCasos; i++)
    {
        resuelveCaso();
    }
    
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}
