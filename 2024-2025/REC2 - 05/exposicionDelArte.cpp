#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <numeric>
#include <algorithm>
using namespace std;


/*
REQUISITOS:
Las obras deben salir en orden
Solo se puede hacer el numero de viajes que se indica
Se devuelve el peso como minimo que debe soportar el camion
*/

bool esPosible(const vector<int> &pesos, int maxPeso, int viajes) {
    int suma = 0, viajesNecesarios = 1;
    for (int peso : pesos) {
        if (suma + peso > maxPeso) {
            viajesNecesarios++;
            suma = peso;
            if (viajesNecesarios > viajes) return false;
        } else {
            suma += peso;
        }
    }
    return true;
}

int pesoMinimo(const vector<int> &pesos, int viajes) {
    int ini = *max_element(pesos.begin(), pesos.end());
    int fin = accumulate(pesos.begin(), pesos.end(), 0);
    while (ini < fin) {
        int mid = (ini + fin) / 2;
        if (esPosible(pesos, mid, viajes)) {
            fin = mid;
        } else {
            ini = mid + 1;
        }
    }
    return ini;
}


bool resuelveCaso() {
    int obras, viajes; //numero de obras que tiene el pasillo y el numero maximo de viajes que puede hacer
    cin >> obras >> viajes;
    if(obras == 0 && viajes == 0) return false;
    vector <int> pesos (obras);
    for (int i = 0; i < obras; i++)
    {
        cin >> pesos[i];
    }
    cout << pesoMinimo(pesos, viajes) << '\n';
    

    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("sample.in");  //o cambia el nombre por el fichero que te descargues
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    while (resuelveCaso()) {}
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
   
#endif

    return 0;
}

