#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

//cuanto tiempo como minimo va a estar el coche sin parar 
int tiempoMaximoEnElCoche (const vector <int> &v, int nParadas, int propuesta) {
    int paradas = v[0]; //el valor del tiempo minimo, es el maximo del vector
    int tiempo = v[0];
    for (int i = 1; i < v.size(); ++i) {
        if (tiempo + v[i] <= propuesta) {
            tiempo += v[i];
        }
        else {
            paradas = max(paradas, tiempo);
            tiempo = v[i];
            --nParadas;
        }
        if (nParadas < 0) {
            return propuesta;
    }
    }
    return paradas;
    
}

bool resuelveCaso() {
    int n, p; //siendo n el numero de veces que dividimos el camino y p el numero de paradas como maximo que estoy dispuesto a hacer
    cin >> n >> p;
    if(n == 0 && p == 0) return false;
    
    int maximo = 0, sumatorio = 0, aux;
    for (int i = 0; i < n; i++) {
       // cin >> v[i]; //tiempo necesario para recorrer cada tramo
        cin >> aux;
        maximo = max(maximo, aux);
        sumatorio += aux;
    }
    vector <int> v;
    for (int i = maximo; i <= sumatorio; i++) {
        v.push_back(i);
    }

   

    cout << tiempoMaximoEnElCoche(v, p, maximo) << "\n";
    
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

