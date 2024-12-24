#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct vinilos {
    int duracion;
    int puntuacion;
};


void vueltaAtras(int N, int k, int dur1, int dur2, int duracionTotal, vector<vinilos>const& canciones, vector<int>& sol, vector<bool>& usadas, int& puntuacion, int& puntuacionMejor) {

    sol[k] = 1;
    if (!usadas[k]) {
        usadas[k] = true;
        puntuacion += canciones[k].puntuacion;
        dur1 += canciones[k].duracion;

        if (dur1 <= duracionTotal) {
            if (k == N - 1) {
                puntuacionMejor = puntuacion > puntuacionMejor ? puntuacion : puntuacionMejor;
            }
            else vueltaAtras(N, k + 1, dur1, dur2, duracionTotal, canciones, sol, usadas, puntuacion, puntuacionMejor);

        }
    }

    dur1 -= canciones[k].duracion;
    puntuacion -= canciones[k].puntuacion;
    usadas[k] = false;


    sol[k] = 2;
    if (!usadas[k]) {
        usadas[k] = true;
        puntuacion += canciones[k].puntuacion;
        dur2 += canciones[k].duracion;

        if (dur2 <= duracionTotal && sol[k] == 2) {
            if (k == N - 1) {
                puntuacionMejor = puntuacion > puntuacionMejor ? puntuacion : puntuacionMejor;
            }
            else vueltaAtras(N, k + 1, dur1, dur2, duracionTotal,canciones, sol, usadas, puntuacion, puntuacionMejor);
        }
        
    }

    dur2 -= canciones[k].duracion;
    puntuacion -= canciones[k].puntuacion;
    usadas[k] = false;
    

    sol[k] = 0;
    if (k == N - 1) {
        puntuacionMejor = puntuacion > puntuacionMejor ? puntuacion : puntuacionMejor;
    }
    else {
        vueltaAtras(N, k + 1, dur1, dur2, duracionTotal, canciones, sol, usadas, puntuacion, puntuacionMejor);
    }
    
}

int auxiliar(int N, int duracionTotal, vector<vinilos>const& canciones) {
    vector<bool>usadas(N, false);
    vector<int>sol(N, 0);
    int puntuacion = 0;
    int puntiacionMejor = 0;
    vueltaAtras(N, 0, 0, 0, duracionTotal, canciones, sol, usadas, puntuacion, puntiacionMejor);
    return puntiacionMejor;
}

bool resuelveCaso() {
    int N;
    cin >> N;
    if (N == 0)
        return false;
    int duracionTotal;
    cin >> duracionTotal;

    vector<vinilos> canciones(N);
    for (int i = 0; i < N; i++) cin >> canciones[i].duracion >> canciones[i].puntuacion;

    cout << auxiliar(N, duracionTotal, canciones) << '\n';


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