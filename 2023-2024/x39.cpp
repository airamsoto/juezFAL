#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

void trabajos(const vector<int> &personasPorEquipo, const vector<int> &minimosPorProyecto, const vector<int> &maximosPorProyecto,
              const vector<int> &sueldosPorProyecto, int k, vector<int> &sol, vector<int> &mejorSol, int &sueldoact,
              int &mejorSueldo, vector<int> &personasAsignadas, vector<bool> &proyectosCubiertos) {

    int equipos = personasPorEquipo.size();
    int proyectos = minimosPorProyecto.size();

    if (k == equipos) {
        bool todosCubiertos = true;
        for (int j = 0; j < proyectos; ++j) {
            if (personasAsignadas[j] < minimosPorProyecto[j]) {
                todosCubiertos = false;
                break;
            }
        }
        if (todosCubiertos && sueldoact < mejorSueldo) {
            mejorSueldo = sueldoact;
            mejorSol = sol;
        }
        return;
    }

    for (int proyecto = 0; proyecto < proyectos; ++proyecto) {
        if (personasAsignadas[proyecto] + personasPorEquipo[k] <= maximosPorProyecto[proyecto]) {
            sol[k] = proyecto;
            personasAsignadas[proyecto] += personasPorEquipo[k];
            sueldoact += personasPorEquipo[k] * sueldosPorProyecto[proyecto];

            if (sueldoact < mejorSueldo) {
                trabajos(personasPorEquipo, minimosPorProyecto, maximosPorProyecto, sueldosPorProyecto, k + 1, sol, mejorSol, sueldoact, mejorSueldo, personasAsignadas, proyectosCubiertos);
            }

            sueldoact -= personasPorEquipo[k] * sueldosPorProyecto[proyecto];
            personasAsignadas[proyecto] -= personasPorEquipo[k];
        }
    }
}

void resuelveCaso() {
    int equipos, proyectos;
    cin >> equipos >> proyectos;

    vector<int> personasPorEquipo(equipos);
    vector<int> minimosPorProyecto(proyectos);
    vector<int> maximosPorProyecto(proyectos);
    vector<int> sueldosPorProyecto(proyectos);

    for (int i = 0; i < equipos; ++i) {
        cin >> personasPorEquipo[i];
    }
    for (int i = 0; i < proyectos; ++i) {
        cin >> minimosPorProyecto[i];
    }
    for (int i = 0; i < proyectos; ++i) {
        cin >> maximosPorProyecto[i];
    }
    for (int i = 0; i < proyectos; ++i) {
        cin >> sueldosPorProyecto[i];
    }

    int sueldoAct = 0, mejorSueldo = INT_MAX;
    vector<int> sol(equipos, -1);
    vector<int> mejorSol(equipos, -1);
    vector<int> personasAsignadas(proyectos, 0);
    vector<bool> proyectosCubiertos(proyectos, false);

    trabajos(personasPorEquipo, minimosPorProyecto, maximosPorProyecto, sueldosPorProyecto, 0, sol, mejorSol, sueldoAct, mejorSueldo, personasAsignadas, proyectosCubiertos);

    if (mejorSueldo == INT_MAX) {
        cout << "NO" << '\n';
    } else {
        cout << mejorSueldo << '\n';
    }
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        resuelveCaso();
    }

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}