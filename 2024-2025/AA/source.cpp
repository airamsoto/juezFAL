#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct tAtraccion {
    string nombre;
    int tiempo;
    int satisfaccion;
    bool acuatica;
};

void func(const vector<tAtraccion> &datos, int n, int tiempo, int &satisfaccionActual, int &tiempoActual, int &mejorSatisfaccion, int k, vector<bool> &sol, int &mojados, int &salpicados) {
    
    //SI
    satisfaccionActual += datos[k].satisfaccion;
    tiempoActual += datos[k].tiempo;
    if (datos[k].acuatica) mojados++;
    else salpicados++;
    sol[k] = true;

    if (tiempoActual <= tiempo) {
        if (k == n - 1) {
            if (satisfaccionActual > mejorSatisfaccion && mojados <= salpicados) {
                mejorSatisfaccion = satisfaccionActual;
            }
        } else {
            func(datos, n, tiempo, satisfaccionActual, tiempoActual, mejorSatisfaccion, k + 1, sol, mojados, salpicados);
        }
    }

    sol[k] = false;
    satisfaccionActual -= datos[k].satisfaccion;
    tiempoActual -= datos[k].tiempo;
    if (datos[k].acuatica) mojados--;
    else salpicados--;

//NO
    if (k == n - 1) {
        if (satisfaccionActual > mejorSatisfaccion && mojados <= salpicados) {
            mejorSatisfaccion = satisfaccionActual;
        }
    } else {
        func(datos, n, tiempo, satisfaccionActual, tiempoActual, mejorSatisfaccion, k + 1, sol, mojados, salpicados);
    }
}

bool resuelveCaso() {
    int nAtracciones, tiempo;
    cin >> nAtracciones >> tiempo;
    if (nAtracciones == 0 && tiempo == 0) return false;

    vector<tAtraccion> datos(nAtracciones);
    for (int i = 0; i < nAtracciones; i++) {
        cin >> datos[i].nombre >> datos[i].tiempo >> datos[i].satisfaccion >> datos[i].acuatica;
    }

    int satisfaccionActual = 0, tiempoActual = 0, mejorSatisfaccion = 0, mojados = 0, salpicados = 0;
    vector<bool> sol(nAtracciones, false);

    func(datos, nAtracciones, tiempo, satisfaccionActual, tiempoActual, mejorSatisfaccion, 0, sol, mojados, salpicados);

    if (mejorSatisfaccion == 0) {
        cout << "NINGUNA" << endl;
    } else {
        cout << mejorSatisfaccion << endl;
    }

    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso()) {}

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}
