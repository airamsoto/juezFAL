//airam martin soto e37
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


typedef struct {
    int canicas;
    string nombre;
} tJugador;


string torneo(const vector<tJugador> &jugadores, int inicio, int final, int &cantidad) {
    if (inicio == final) {

        cantidad = jugadores[inicio].canicas;
        return jugadores[inicio].nombre;

    } else {
        int medio = (final + inicio) / 2;
        int cantidadIzq = 0;
        int cantidadDer = 0;
        string ganadorIzq = torneo(jugadores, inicio, medio, cantidadIzq);
        string ganadorDer = torneo(jugadores, medio + 1, final, cantidadDer);
        if (cantidadIzq >= cantidadDer) {
            cantidad += cantidadIzq + cantidadDer / 2;
            return ganadorIzq;
        } else {
            cantidad += cantidadDer + cantidadIzq / 2;
            return ganadorDer;
        }
    }
}


bool resuelveCaso() {
    int f;
    cin >> f;
    if (!std::cin)
        return false;

    vector<tJugador> jugadores(f);


    for (int i = 0; i < f; ++i) {
        cin >> jugadores[i].nombre;
        cin >> jugadores[i].canicas;
    }
    int cantidad = 0;
    string ganador = torneo(jugadores, 0, f - 1, cantidad);
    cout << ganador << " " << cantidad << endl;


    return true;
}

int main() {
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    // Elimina la línea system("pause") para evitar problemas en algunos entornos
#endif

    return 0;
}
