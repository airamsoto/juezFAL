#include <iostream>
#include <vector>
#include <climits>
#include <fstream>
using namespace std;

bool esValida(const vector<int>& personasPorCanoa, const vector<int>& pesoActual, int canoa, const vector<int>& pesos, int amigo, int pesoMaximo, const vector<vector<int>>& relas) {
    if (personasPorCanoa[canoa] >= 3 || pesoActual[canoa] + pesos[amigo] > pesoMaximo) {
        return false;
    }
    for (int i = 0; i < personasPorCanoa.size(); i++) {
        if (relas[amigo][i] == 1 && personasPorCanoa[i] > 0 && i == canoa) {
            return false; 
        }
    }
    return true;
}
void canoas(const vector<int>& pesos, const vector<vector<int>>& relas, vector<int>& pesoActual, int& numeroCanoasActual,
            int amigo, int nAmigos, vector<int>& personasPorCanoa, int nCanoas, int pesoMaximo, int& canoasMinimas) {
    for (int canoa = 0; canoa < nCanoas; ++canoa) {
        if (esValida(personasPorCanoa, pesoActual, canoa, pesos, amigo, pesoMaximo, relas)) {
            pesoActual[canoa] += pesos[amigo];
            personasPorCanoa[canoa]++;
            if (canoa >= numeroCanoasActual) {
                numeroCanoasActual++;
            }

            if (amigo == nAmigos - 1) {
                canoasMinimas = min(canoasMinimas, numeroCanoasActual);
            } else {
                canoas(pesos, relas, pesoActual, numeroCanoasActual, amigo + 1, nAmigos, personasPorCanoa, nCanoas, pesoMaximo, canoasMinimas);
            }

            pesoActual[canoa] -= pesos[amigo];
            personasPorCanoa[canoa]--;
            if (canoa == numeroCanoasActual - 1 && personasPorCanoa[canoa] == 0) {
                numeroCanoasActual--;
            }
        }
    }
}

// Resolver un caso de prueba
void resuelveCaso() {
    int amigos, nCanoas, pesoMaximo;
    cin >> amigos >> nCanoas >> pesoMaximo;

    vector<int> pesos(amigos);
    for (int i = 0; i < amigos; ++i) {
        cin >> pesos[i];
    }

    vector<vector<int>> relas(amigos, vector<int>(amigos));
    for (int i = 0; i < amigos; ++i) {
        for (int j = 0; j < amigos; ++j) {
            cin >> relas[i][j];
        }
    }

    vector<int> pesoActual(nCanoas, 0);
    vector<int> personasPorCanoa(nCanoas, 0);
    int numeroCanoasActual = 0;
    int canoasMinimas = INT_MAX;

    canoas(pesos, relas, pesoActual, numeroCanoasActual, 0, amigos, personasPorCanoa, nCanoas, pesoMaximo, canoasMinimas);

    if (canoasMinimas == INT_MAX) {
        cout << "IMPOSIBLE\n";
    } else {
        cout << canoasMinimas << "\n";
    }
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int nCasos;
    cin >> nCasos;
    for (int i = 0; i < nCasos; ++i) {
        resuelveCaso();
    }

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}
