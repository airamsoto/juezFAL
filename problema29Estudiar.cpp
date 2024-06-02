//airam martin soto e37
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

typedef struct {
    int canicas;
    string nombre;
}tJugador;

tJugador campeon (vector <tJugador> &jugador, int inicio, int final) {
    //VERSION ANTEORIOR QUE DABA CORRECT
   /* if(inicio == final-1) {
        if(jugador[inicio].canicas >= jugador[final].canicas) {
            jugador[inicio].canicas+= (jugador[final].canicas / 2);
            return jugador[inicio];
        } else {
            jugador[final].canicas+= (jugador[inicio].canicas / 2);
            return jugador[final];
        }
    } else {
        int medio = (final+inicio)/2;
        tJugador ganadorIzquierda = campeon(jugador, inicio, medio);
        tJugador ganadorDerecha = campeon(jugador, medio+1, final);
        if(ganadorIzquierda.canicas >= ganadorDerecha.canicas) {
            ganadorIzquierda.canicas+= ganadorDerecha.canicas/2;

            return ganadorIzquierda;
        }
        else {
            ganadorDerecha.canicas+= ganadorIzquierda.canicas/2;
            return ganadorDerecha;
        }
    }*/
   //PROBAR VERSION MEJORADA que da CORRECT
   if(inicio == final) {
       return jugador[inicio];
   }else {
       int medio = (final+inicio)/2;
       tJugador ganadorIzquierda = campeon(jugador, inicio, medio);
       tJugador ganadorDerecha = campeon(jugador, medio+1, final);
       if(ganadorIzquierda.canicas >= ganadorDerecha.canicas) {
           ganadorIzquierda.canicas+= ganadorDerecha.canicas/2;
           return ganadorIzquierda;
       }
       else {
           ganadorDerecha.canicas+= ganadorIzquierda.canicas/2;
           return ganadorDerecha;
       }

   }
}

bool resuelveCaso() {
    int f;
    cin >> f;
    if (!std::cin)
        return false;
    vector<tJugador> jugador (f);
    for (int i = 0; i < f; ++i) {
        cin >> jugador[i].nombre;
        cin >> jugador[i].canicas;
    }
    tJugador ganador = campeon (jugador, 0, f-1);
    cout << ganador.nombre << " " << ganador.canicas << endl;




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
