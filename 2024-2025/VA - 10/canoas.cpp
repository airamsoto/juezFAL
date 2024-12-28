#include <iostream>
#include <vector>
#include <climits>
#include <fstream>
using namespace std;

bool esValida(const vector<vector<int>> &sol, const vector<vector<int>> &enemistades, int canoa, int k) {
    for (int i = 0; i < sol[canoa].size(); i++) {
        if (enemistades[sol[canoa][i]][k] == 1) return false;
    }
    return true;
}

void canoas(const vector<vector<int>> &enemistades, const vector<int> &pesosAmigos, vector<int> &pesoCanoas, int M, int N, int pesoMax, int k, int &numeroCanoasActual, int &mejorNumeroCanoas, bool &haySol, vector<vector<int>> &sol) {
    for (int canoa = 0; canoa < N; canoa++) {
        if (esValida(sol, enemistades, canoa, k) && pesoCanoas[canoa] + pesosAmigos[k] <= pesoMax) {
            bool nuevaCanoa = sol[canoa].empty();
            pesoCanoas[canoa] += pesosAmigos[k];
            sol[canoa].push_back(k);
            if (nuevaCanoa) numeroCanoasActual++;
            if (k == M - 1) {
                haySol = true;
                mejorNumeroCanoas = min(mejorNumeroCanoas, numeroCanoasActual);
            } else if(numeroCanoasActual < mejorNumeroCanoas){
                canoas(enemistades, pesosAmigos, pesoCanoas, M, N, pesoMax, k + 1, numeroCanoasActual, mejorNumeroCanoas, haySol, sol);
            }
            if (nuevaCanoa) numeroCanoasActual--;
            pesoCanoas[canoa] -= pesosAmigos[k];
            sol[canoa].pop_back();
        }
    }
}

void resuelveCaso() {
    int M, N, K; // siendo M amigos y N canoas, donde cada canoa puede transportar [1-3] personas si no supere k kilos
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
    vector<int> pesoCanoas(N, 0);
    int numeroCanoasActual = 0, mejorNumeroCanoas = INT_MAX;
    vector<vector<int>> sol(N, vector<int>(0));
    bool haySol = false;

    canoas(enemistades, pesosAmigos, pesoCanoas, M, N, K, 0, numeroCanoasActual, mejorNumeroCanoas, haySol, sol);

    if (haySol) {
        cout << mejorNumeroCanoas << endl;
    } else {
        cout << "IMPOSIBLE" << endl;
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
