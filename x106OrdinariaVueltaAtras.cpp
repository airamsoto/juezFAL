#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
bool puedeCogerla(const vector<bool> &aprobadas, const vector<int> prerrequisitos, int k) {
    if(aprobadas[k] || (prerrequisitos[k] != -1 && !aprobadas[prerrequisitos[k]])) return false;
    return true;
}
void asignaturas ( const vector<int>&ordenados, vector<bool> &aprobadas,vector<int> &prerrequisitos, vector<int> &creditosAsginatura,vector<int> &costesMatricula, vector<bool>&marcas, int &creditosActuales,
                   int &costeActual, int& mejorCoste, int k, int creditosNecesarios) {
    if(k < aprobadas.size()) {
        int asig = ordenados[k];
        if(!marcas[asig] && puedeCogerla(aprobadas, prerrequisitos, asig)) {
            marcas[asig]= true;
            costeActual+= costesMatricula[asig];
            creditosActuales+= creditosAsginatura[asig];
            if(creditosActuales >= creditosNecesarios) {
                mejorCoste = min(mejorCoste, costeActual);
            }
            else asignaturas(ordenados, aprobadas, prerrequisitos, creditosAsginatura, costesMatricula, marcas, creditosActuales, costeActual, mejorCoste, k +1 , creditosNecesarios);
            costeActual-= costesMatricula[asig];
            creditosActuales-= creditosAsginatura[asig];
            marcas[asig] = false;

        }
        asignaturas(ordenados, aprobadas, prerrequisitos, creditosAsginatura, costesMatricula, marcas, creditosActuales, costeActual, mejorCoste, k +1 , creditosNecesarios);
    }

}

void resuelveCaso(){
    int n, creditos;
    cin >> n >> creditos;
    vector<bool> aprobadas (n);
    vector<int> prerrequisitos (n);
    vector<int> creditosAsginatura (n);
    vector<int> costesMatricula (n);
    string aux;
    for (int i = 0; i < n; ++i) {
        cin >> aux;
        if (aux == "A") aprobadas[i] = true;
        else aprobadas[i] = false;
    }

    for (int i = 0; i < n; ++i) {
        cin >> prerrequisitos[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> creditosAsginatura[i];

    }
    for (int i = 0; i < n; ++i) {
        cin >> costesMatricula[i];

    }
    vector<int> orden(n);
    for (int i = 0; i < n; ++i) {
        orden[i] = i;
    }

    sort(orden.begin(), orden.end(), [&](int a, int b) {
        return (double)creditosAsginatura[a] / costesMatricula[a] > (double)creditosAsginatura[b] / costesMatricula[b];
    });
    int creditosActuales = 0, costeActual = 0, mejorCoste = INT_MAX;
    vector<bool> marcas (n, false);

    asignaturas(orden, aprobadas, prerrequisitos, creditosAsginatura, costesMatricula, marcas, creditosActuales, costeActual, mejorCoste, 0, creditos);
    if (mejorCoste == INT_MAX) cout  << "NO" << '\n';
    else cout << mejorCoste << '\n';

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
