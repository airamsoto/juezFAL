#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


struct tCancion {
    int duracion;
    int satisfaccion;
    double prioridad;
};

void trayecto (const vector<tCancion>& canciones, vector<bool> &usadas, vector <int> &sol, int n, int t1, int t2, int &tiempoIda, int& tiempoVuelta, int &satisfaccionActual, int &satisfaccionMaxima, int k, const vector <int> &acumulados) {
    sol[k] = 1;
    if(!usadas[k]) {
        tiempoIda+=canciones[k].duracion;
        satisfaccionActual+=canciones[k].satisfaccion;
        usadas[k] = true;
        if(tiempoIda <= t1 ) {
            if(k == n -1) {
                if(tiempoIda == t1 && tiempoVuelta == t2)
                satisfaccionMaxima = max (satisfaccionActual, satisfaccionMaxima);
            } else if (satisfaccionActual + acumulados[k+1] > satisfaccionMaxima) {
                trayecto (canciones, usadas, sol, n, t1, t2, tiempoIda, tiempoVuelta, satisfaccionActual, satisfaccionMaxima, k+1, acumulados);
            }
        }
        
    }
    tiempoIda-=canciones[k].duracion;
    satisfaccionActual-=canciones[k].satisfaccion;
    usadas[k] = false;

    sol[k] = 2;
    if(!usadas[k]) {
        tiempoVuelta+=canciones[k].duracion;
        satisfaccionActual+=canciones[k].satisfaccion;
        usadas[k] = true;
        if(tiempoVuelta <= t2) {
            if(k == n -1 ) {
                if(tiempoIda == t1 && tiempoVuelta == t2) satisfaccionMaxima = max (satisfaccionActual, satisfaccionMaxima);
            } else if (satisfaccionActual + acumulados[k+1] > satisfaccionMaxima) {
                trayecto (canciones, usadas, sol, n, t1, t2, tiempoIda, tiempoVuelta, satisfaccionActual, satisfaccionMaxima, k+1, acumulados);
            }
        }
    }
    tiempoVuelta-=canciones[k].duracion;
    satisfaccionActual-=canciones[k].satisfaccion;
    usadas[k] = false;

    sol[k] = 0;
    if(k == n -1) {
        if(tiempoIda == t1 && tiempoVuelta == t2)
        satisfaccionMaxima = max (satisfaccionActual, satisfaccionMaxima);
    } else if (satisfaccionActual + acumulados[k+1] > satisfaccionMaxima) {
        trayecto (canciones, usadas, sol, n, t1, t2, tiempoIda, tiempoVuelta, satisfaccionActual, satisfaccionMaxima, k+1, acumulados);        
    }


}



bool resuelveCaso() {
    int n, t1, t2;
    cin >> n >> t1 >> t2;
    if (n == 0 && t1 == 0 && t2 == 0) return false;
    vector <tCancion> canciones (n);
    for (int i = 0; i < n; i++) {
        cin >> canciones[i].duracion >> canciones[i].satisfaccion;
        canciones[i].prioridad = static_cast<double>( canciones[i].satisfaccion / canciones[i].duracion);
    }
    sort(canciones.begin(), canciones.end(),[](const tCancion&a, const tCancion&b){
        return a.prioridad > b.prioridad;
    });

    vector<bool> usadas (n, false);
    vector <int> sol (n, 0); //si 0 es que no la pone, si 1 va a la ida, si 2 va a la vuelta
    int tiempoIda = 0, tiempoVuelta = 0, satisfaccionActual = 0, satisfaccionMax = -1;
    vector <int> acumulados (n, 0);
    acumulados[n-1] = canciones[n-1].satisfaccion;
    for (int i = n-2; i >=0; i--) {
        acumulados[i] = acumulados[i+1] + canciones[i].satisfaccion;
    }
    trayecto (canciones, usadas, sol, n, t1, t2, tiempoIda, tiempoVuelta, satisfaccionActual, satisfaccionMax, 0, acumulados);   
    if(satisfaccionMax == -1) cout << "Imposible\n";
    else cout << satisfaccionMax << '\n';
    
     
    


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
