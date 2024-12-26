#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct vinilos {
    int duracion;
    int puntuacion;
    double prioridad;
};

void vueltaAtras(int N, int k, int dur1, int dur2, int duracionTotal, vector<vinilos> const& canciones, vector<int>& sol, vector<bool>& usadas, int& puntuacion, int& puntuacionMejor, vector<int> const& acumulados) {

    sol[k] = 1;
    if (!usadas[k]) {
        usadas[k] = true;
        puntuacion += canciones[k].puntuacion;
        dur1 += canciones[k].duracion;

        if (dur1 <= duracionTotal) {
            if (k == N - 1) {
                puntuacionMejor = max(puntuacion, puntuacionMejor);
            }
            else if(puntuacion + acumulados[k] > puntuacionMejor) vueltaAtras(N, k + 1, dur1, dur2, duracionTotal, canciones, sol, usadas, puntuacion, puntuacionMejor, acumulados);
        }

        dur1 -= canciones[k].duracion;
        puntuacion -= canciones[k].puntuacion;
        usadas[k] = false;
    }

    sol[k] = 2;
    if (!usadas[k]) {
        usadas[k] = true;
        puntuacion += canciones[k].puntuacion;
        dur2 += canciones[k].duracion;

        if (dur2 <= duracionTotal) {
            if (k == N - 1) {
                puntuacionMejor = max(puntuacion, puntuacionMejor);
            }
            else if(puntuacion + acumulados[k] > puntuacionMejor)vueltaAtras(N, k + 1, dur1, dur2, duracionTotal, canciones, sol, usadas, puntuacion, puntuacionMejor, acumulados);
        }

        dur2 -= canciones[k].duracion;
        puntuacion -= canciones[k].puntuacion;
        usadas[k] = false;
    }

    sol[k] = 0;
    if (k == N - 1) {
        puntuacionMejor = max(puntuacion, puntuacionMejor);
    }
    else {
        if(puntuacion + acumulados[k] > puntuacionMejor)vueltaAtras(N, k + 1, dur1, dur2, duracionTotal, canciones, sol, usadas, puntuacion, puntuacionMejor, acumulados);
    }
}

int auxiliar(int N, int duracionTotal, vector<vinilos> const& canciones) {
    vector<bool> usadas(N, false);
    vector<int> sol(N, 0);
    vector<int> acumulados(N, 0);
    int puntuacion = 0;
    int puntuacionMejor = 0;

    acumulados[N - 1] = canciones[N - 1].puntuacion;
    for (int i = N - 2; i >= 0; --i) {
        acumulados[i] = acumulados[i + 1] + canciones[i].puntuacion;
    }

    vueltaAtras(N, 0, 0, 0, duracionTotal, canciones, sol, usadas, puntuacion, puntuacionMejor, acumulados);
    return puntuacionMejor;
}

bool resuelveCaso() {
    int N;
    cin >> N;
    if (N == 0)
        return false;
    int duracionTotal;
    cin >> duracionTotal;

    vector<vinilos> canciones(N);
    vector <int> acumulados (N, 0);
    for (int i = 0; i < N; i++) {
        cin >> canciones[i].duracion >> canciones[i].puntuacion;
        canciones[i].prioridad = static_cast<double>( canciones[i].puntuacion / canciones[i].duracion);
       
    }
    sort(canciones.begin(), canciones.end(), [](vinilos const& a, vinilos const& b) {
       return a.prioridad > b.prioridad;
    });

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
