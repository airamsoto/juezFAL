

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct tJugador {
    int puntos;
    string nombre;
};

tJugador ganadorCanincas (const vector<tJugador> &jugadores, int ini, int fin) {
    if(ini == fin) return jugadores[ini];
    else {
        int m = (ini+fin)  / 2;
        tJugador jugadorDer = ganadorCanincas(jugadores, m+1, fin);
        tJugador jugadorIzq = ganadorCanincas(jugadores, ini, m);

        if (jugadorDer.puntos > jugadorIzq.puntos) {
           jugadorDer.puntos += jugadorIzq.puntos /2;
            return jugadorDer;
        } else {
            jugadorIzq.puntos += jugadorDer.puntos / 2;
            return jugadorIzq;
        }
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
