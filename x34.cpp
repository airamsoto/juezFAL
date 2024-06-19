#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void
quitaNieves(const vector<vector<int>> &calidades, const vector<int> &anchurasCarros, const vector<int> &anchurasCaminos, vector<bool> &carrosUsados,
            vector<bool> &caminosUsados, int k, int n, vector<int> &sol, int &calidad, vector<int> &mejor_sol, int &mejorCalidad, vector<int> &acum) {

    for (int carros = 0; carros < anchurasCarros.size(); carros++) {
        if (!carrosUsados[carros] && anchurasCarros[carros] <= anchurasCaminos[k]) {
            if (anchurasCarros[carros] <= anchurasCaminos[k]) {
                carrosUsados[carros] = true;
                calidad += calidades[carros][k];
                sol[k] = carros;
                if (k == n - 1) {
                    if (mejorCalidad < calidad) {
                        mejorCalidad = calidad;
                        mejor_sol = sol;
                    }
                } else if (calidad + acum[k + 1] > mejorCalidad) {
                    quitaNieves(calidades, anchurasCarros, anchurasCaminos, carrosUsados, caminosUsados, k + 1, n, sol,
                                calidad, mejor_sol, mejorCalidad, acum);
                }
            }
            carrosUsados[carros] = false;
            calidad -= calidades[carros][k];
        }
    }
    if (k == n - 1) {
        mejorCalidad = max(mejorCalidad, calidad);
    } else {
        if (k != n - 1 && mejorCalidad < calidad + acum[k + 1]) {
            quitaNieves(calidades, anchurasCarros, anchurasCaminos, carrosUsados, caminosUsados, k + 1, n, sol,
                        calidad, mejor_sol, mejorCalidad, acum);
        }
    }

}


void resuelveCaso() {
    int nCarros, nCaminos, calidad = 0, mejorCalidad = 0;
    cin >> nCarros >> nCaminos;

    vector<int> anchurasCarros(nCarros);
    vector<int> anchurasCaminos(nCaminos);
    vector<vector<int>> calidades(nCarros, vector<int>(nCaminos));
    vector<bool> carrosUsados(nCarros, false);
    vector<bool> caminosUsados(nCaminos, false);
    vector<int> sol(nCaminos);
    vector<int> mejor_sol(nCaminos);
    vector<int> acum(nCaminos, 0);

    for (int i = 0; i < nCarros; i++) {
        cin >> anchurasCarros[i];
    }

    for (int i = 0; i < nCaminos; i++) {
        cin >> anchurasCaminos[i];
    }
    vector<int> mejoresCalidades(nCaminos, -1);
    for (int i = 0; i < nCarros; i++) {
        for (int j = 0; j < nCaminos; j++) {
            cin >> calidades[i][j];
            mejoresCalidades[j] = max(mejoresCalidades[j], calidades[i][j]);

        }
    }
    acum[acum.size() - 1] = mejoresCalidades[mejoresCalidades.size() - 1];
    for (int i = nCaminos - 2; i >= 0; i--) {
        acum[i] = acum[i + 1] + mejoresCalidades[i];
    }

    quitaNieves(calidades, anchurasCarros, anchurasCaminos, carrosUsados, caminosUsados, 0, nCaminos, sol, calidad,
                mejor_sol, mejorCalidad, acum);
    cout << mejorCalidad << endl;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("sample.in ");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    unsigned int numCasos;
    std::cin >> numCasos;

    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}