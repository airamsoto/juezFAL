

#include <iostream>
#include <vector>
#include <fstream>
#include <climits>

using namespace std;

bool esValida(const vector<vector<int>>& vetos, const vector<int>& sol, int k) {

    if (k > 0) {
        int artistaActual = sol[k];
        int artistaAnterior = sol[k - 1];
        if (vetos[artistaActual][artistaAnterior] == 0) {
            return false;
        }
    }
    return true;
}

void concierto ( const vector<vector<int>> &donaciones , const vector<vector<int>> &vetos, vector <bool>& marcas, vector <int>& acumulados, int k, int n, int& donacionesActuales, int& donacionMaxima, vector<int>& sol, vector <int>& mejorSol){
    for (int plaza = 0; plaza < n; ++plaza) {
        if(!marcas[plaza]) {
            sol[k] = plaza;
            if(esValida(vetos, sol, k)) {
                donacionesActuales += donaciones[plaza][k];
                marcas[plaza] = true;
                if(k == n -1) {
                    if (donacionesActuales > donacionMaxima) {
                        donacionMaxima = donacionesActuales;
                        mejorSol = sol;
                    }
                } else if(donacionesActuales + acumulados[k] > donacionMaxima){
                    concierto(donaciones, vetos, marcas, acumulados, k+1, n, donacionesActuales, donacionMaxima,sol, mejorSol);
                }

                donacionesActuales-= donaciones[plaza][k];
                marcas[plaza] = false;

            }

        }

    }
}






void resuelveCaso() {
    int artistas;
    cin >> artistas;
    vector<vector<int>> donaciones (artistas, vector<int> (artistas));
    vector<vector<int>> vetos (artistas, vector<int> (artistas));
    vector<int> mejoresResultados (artistas, -1);



    for (int i = 0; i < artistas; ++i) {
        for (int j = 0; j < artistas; ++j) {
            cin >> donaciones[i][j];
            if (donaciones[i][j] > mejoresResultados[j]) {
                mejoresResultados[j] = donaciones[i][j];
            }
        }
    }

    for (int i = 0; i < artistas; ++i) {
        for (int j = 0; j < artistas; ++j) {
            cin >> vetos[i][j];
        }
    }

    vector<int> acumulados(artistas);
    acumulados[artistas - 1] = mejoresResultados[artistas - 1];
    for (int i = artistas - 2; i >= 0; --i) {
        acumulados[i] = mejoresResultados[i] + acumulados[i + 1];
    }
    int donacionesActuales = 0, donacionMaxima = INT_MIN;
    vector<int> sol (artistas);
    vector<int> mejorSol (artistas);

    vector<bool> marcas (artistas, false);
    concierto(donaciones, vetos, marcas, acumulados, 0, artistas, donacionesActuales, donacionMaxima,sol, mejorSol);

    if(donacionMaxima == INT_MIN) cout << "NEGOCIA CON LOS ARTISTAS" << '\n';
    else cout << donacionMaxima << '\n';
}


int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int nCasos;
    cin >> nCasos;
    for (int i = 0; i < nCasos; ++i) {
        resuelveCaso();
    }

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);//system("pause");
#endif
    return 0;
}
