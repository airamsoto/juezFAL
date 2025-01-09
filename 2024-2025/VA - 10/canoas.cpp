#include <iostream>
#include <vector>
#include <climits>
#include <fstream>
using namespace std;

struct tCanoa {
    vector<int> personas;
    int contPersonas;
    int pesoDispo;
    tCanoa(int k) : contPersonas(0), pesoDispo(k) {
        personas = vector<int>(3);
    }
};

bool esValida(const vector<vector<int>> &enemistades, const vector<int> &pesosAmigos, int canoa, int k, const vector<tCanoa> &canoasSol) {
    if (canoasSol[canoa].pesoDispo - pesosAmigos[k] < 0)
        return false;
    if (canoasSol[canoa].contPersonas >= 3)
        return false;
    for (int j = 0; j < canoasSol[canoa].contPersonas; j++) {
        int pEnCanoa = canoasSol[canoa].personas[j];
        if (enemistades[pEnCanoa][k] == 1)
            return false;
    }
    return true;
}
void vueltaAtras(const vector<vector<int>> &enemistades, const vector<int> &pesosAmigos, int k, int n, int m, vector<int> &personasSol, vector<tCanoa> &canoasSol, int pesoEntrada, int &numCanoas, int &maxCanoas, bool &posible) {
    for (int i = 0; i < n; i++) {
        if (esValida(enemistades, pesosAmigos, i, k, canoasSol)) {
            canoasSol[i].personas[canoasSol[i].contPersonas] = k;
            personasSol[k] = i;
            // MARCAJE
            canoasSol[i].contPersonas++;
            if (canoasSol[i].pesoDispo == pesoEntrada)
                numCanoas++;
            canoasSol[i].pesoDispo -= pesosAmigos[k];
            if (k == m - 1) {
                if (numCanoas < maxCanoas) {
                    posible = true;
                    maxCanoas = numCanoas;
                }
            } else  {
                vueltaAtras(enemistades, pesosAmigos, k + 1, n, m, personasSol, canoasSol, pesoEntrada, numCanoas, maxCanoas, posible);
            }
            // DESMARCAJE
            canoasSol[i].contPersonas--;
            canoasSol[i].pesoDispo += pesosAmigos[k];
            if (canoasSol[i].pesoDispo == pesoEntrada)
                numCanoas--;
        }
    }
}

void resuelveCaso() {
    int M, N, K; // M amigos, N canoas, K peso máximo
    cin >> M >> N >> K;
    vector<int> pesosAmigos(M);
    for (int i = 0; i < M; i++) {
        cin >> pesosAmigos[i];
    }
    vector<vector<int>> enemistades(M, vector<int>(M));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cin >> enemistades[i][j];
        }
    }

    vector<int> personasSol(M);
    vector<tCanoa> canoasSol(N, K);
    bool posible = false;
    int numCanoas = 0;
    int maxCanoas = INT_MAX;
    vueltaAtras(enemistades, pesosAmigos, 0, N, M, personasSol, canoasSol, K, numCanoas, maxCanoas, posible);

    if (posible)
        cout << maxCanoas << "\n";
    else
        cout << "IMPOSIBLE\n";
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
