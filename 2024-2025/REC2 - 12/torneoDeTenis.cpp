#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct tJugador {
    string nombre;
    int partidosJugados = 0;
};

// Función recursiva "divide y vencerás"
tJugador partidos(const vector<string>& jugadores, int ini, int fin, int rondaActual, int rondaObjetivo) {
    if (ini == fin - 1) { // Caso base: un solo jugador
        if (jugadores[ini] == "NP") {
            return {"NP", 0};
        }
        return {jugadores[ini], 0};
    }

    int mitad = (ini + fin) / 2;

    // Resolver las dos mitades
    tJugador izq = partidos(jugadores, ini, mitad, rondaActual + 1, rondaObjetivo);
    tJugador der = partidos(jugadores, mitad, fin, rondaActual + 1, rondaObjetivo);

    tJugador resultado;
    if (izq.nombre == "NP" && der.nombre != "NP") {
        resultado = der; // Pasa el jugador de la derecha
    } else if (izq.nombre != "NP" && der.nombre == "NP") {
        resultado = izq; // Pasa el jugador de la izquierda
    } else if (izq.nombre == "NP" && der.nombre == "NP") {
        resultado = {"NP", 0}; // Ninguno pasa
    } else {
        // Ambos jugadores están presentes
        resultado.nombre = izq.nombre; // Gana el jugador de la izquierda
        if (rondaActual <= rondaObjetivo) {
            resultado.partidosJugados = izq.partidosJugados + der.partidosJugados + 1; // Contar el partido
        } else {
            resultado.partidosJugados = izq.partidosJugados + der.partidosJugados; // No contar fuera de la ronda
        }
    }

    return resultado;
}

// Leer y procesar cada caso de prueba
bool resuelveCaso() {
    int nJugadores, numeroDeRonda;
    cin >> nJugadores >> numeroDeRonda;
    if (!cin) return false;

    vector<string> jugadores(nJugadores);
    for (int i = 0; i < nJugadores; ++i) {
        cin >> jugadores[i];
    }

    tJugador resultado = partidos(jugadores, 0, nJugadores, 1, numeroDeRonda);
    cout << resultado.partidosJugados << '\n';

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
