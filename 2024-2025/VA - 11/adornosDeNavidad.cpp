#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

    struct tAdorno {
    int precio;
    int superficie;
}; 

void decoracion (const vector <tAdorno> &adornos, int presupuesto, int& precioActual, int& superficieActual, int&mejorSuperficie, vector<bool> &sol,
 int k, int n, const vector<int>& acumuladores) {
    sol[k] = true;
    precioActual+=adornos[k].precio;
    superficieActual+=adornos[k].superficie;
    if(precioActual <= presupuesto) {
        if(k == n -1) {
            if(superficieActual > mejorSuperficie) {
                mejorSuperficie = superficieActual;
            } 
        } else  if(superficieActual + acumuladores[k+1] > mejorSuperficie) decoracion (adornos, presupuesto, precioActual, superficieActual, mejorSuperficie, sol, k+1, n ,acumuladores);
    }
    precioActual-=adornos[k].precio;
    superficieActual-=adornos[k].superficie;

    sol[k] = false;
        if(k == n -1) {
            if(superficieActual > mejorSuperficie) {
                mejorSuperficie = superficieActual;
            } 
        } else if(superficieActual + acumuladores[k+1] > mejorSuperficie) decoracion (adornos, presupuesto, precioActual, superficieActual, mejorSuperficie, sol, k+1, n, acumuladores);
}

bool resuelveCaso() {
    int n, presupuesto;
    cin >>  n;
    if(!cin) return false;
    cin >> presupuesto;
    vector <tAdorno> adornos (n);
    vector <int> acumuladores (n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> adornos[i].precio >> adornos[i].superficie;
    }
    acumuladores[n - 1] = adornos[n - 1].superficie;
    for (int i = n - 2; i >= 0; i--) {
        acumuladores[i] = adornos[i].superficie + acumuladores[i + 1];
    }
    
    int precioActual = 0, superficieActual = 0, mejorSuperficie = -1;
    vector <bool> sol (n);
    decoracion (adornos, presupuesto, precioActual, superficieActual, mejorSuperficie, sol, 0, n, acumuladores);
    cout << mejorSuperficie << '\n';

    return true;

}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso()){}
    
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}
