#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

void coinvite(const vector<vector<int>>& datos, vector<int>& sol, vector<bool>& familiarOcupado, int& contadorSol, int& maximaSatisfaccion, int &satisfaccionActual, int &numeroCoincidentes, int posTia, int N, int k, int M, const vector <int> &maximos) {
    for (int familiar = 0; familiar < N; familiar++) {

        if(!familiarOcupado[familiar] && datos[k][familiar] >= 0) { //revisar condicion numeroCoincidentes

            if(k == familiar) numeroCoincidentes++;
            satisfaccionActual+= datos[k][familiar];
            familiarOcupado[familiar] = true;
            sol[k] = familiar;

            if(sol.size() -1 == k) { //posibe sol
                if(numeroCoincidentes <= M/3 && familiarOcupado[posTia]) {
                    if(satisfaccionActual > maximaSatisfaccion) {
                        contadorSol = 1;
                        maximaSatisfaccion = satisfaccionActual;
                    } else if (satisfaccionActual == maximaSatisfaccion) contadorSol++;

                }
            } else if (numeroCoincidentes <= M/3 && k < M -1 && satisfaccionActual + maximos[k+1] >= maximaSatisfaccion) coinvite (datos, sol, familiarOcupado, contadorSol, maximaSatisfaccion, satisfaccionActual, numeroCoincidentes, posTia, N, k+1, M, maximos);


            if(k == familiar) numeroCoincidentes--;
            satisfaccionActual-= datos[k][familiar];
            familiarOcupado[familiar] = false;
        }
    }
   
}

bool resuelveCaso() {
    int N, M, T;
    cin >> N;
    if (N == 0) return false;
    cin >> M >> T;
    vector <int> maximos (M, 0);
    vector<vector<int>> S(M, vector<int>(N));
    
    for (int i = 0; i < M; ++i) {
         for (int j = 0; j < N; ++j) {
            cin >> S[i][j];
           if(maximos[i] < S[i][j]) {
               maximos[i] = S[i][j];
           }
        }
    }
    for (int i = M-2; i >= 0; --i) {
        maximos[i] += maximos[i+1];
    }

    vector<int> sol(M);
    vector<bool> familiarOcupado(N, false);
    int contadorSol = 0, maximaSatisfaccion = -1, satisfaccionActual = 0, numeroCoincidentes = 0;
    coinvite(S, sol, familiarOcupado, contadorSol, maximaSatisfaccion, satisfaccionActual, numeroCoincidentes, T, N, 0, M, maximos);

    if (maximaSatisfaccion >= 0) {
        cout << maximaSatisfaccion << " " << contadorSol << '\n';
    }
    else 
        cout << "No\n";

    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}

