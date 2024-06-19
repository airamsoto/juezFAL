

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
struct tJugador {
    int puntos;
    string nombre;
};

tJugador ganadorCanincas (const vector<tJugador>& jugadores, int ini, int fin) {
    if (ini == fin) return jugadores[ini];
    else {
        int m = (ini + fin) /2;
        tJugador izq = ganadorCanincas(jugadores, ini, m);
        tJugador der = ganadorCanincas(jugadores, m+1, fin);

        tJugador ganador;
        if(izq.puntos >= der.puntos) {
            ganador.puntos = izq.puntos + der.puntos / 2;
            ganador.nombre = izq.nombre;
        } else {
            ganador.puntos = der.puntos + izq.puntos/2;
            ganador.nombre = der.nombre;
        }
        return ganador;
    }
}
bool resuelveCaso() {

    int n;
    cin >> n;
    if (!std::cin) return false;

    vector<tJugador> jugadores(n);


    for (int i = 0; i < n; ++i) {
        cin >> jugadores[i].nombre;
        cin >> jugadores[i].puntos;
    }

    tJugador ganador = ganadorCanincas(jugadores, 0, n-1);
    cout << ganador.nombre << " " << ganador.puntos << '\n';

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
