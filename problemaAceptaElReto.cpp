#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
//falla el caso de prueba en el cual el menor de la parte izquierda es mayor que todos los de la parte derecha es decir que esten ordenador a la derecha




int cambios(vector<int>& vc, int ini, int fin, int suma) {
    //revisar casos 7,6,5
    if (ini < fin) {
        int medio = (ini + fin) / 2;

        int izquierda = cambios(vc, ini, medio, suma);
        int derecha = cambios(vc, medio + 1, fin, suma);
        int i = ini, j = medio +1;
        while (i <= medio && j <= fin) {
            if (vc[i] > vc[j]) {
                suma += medio - i + 1;
                j++;
            } else {
                i++;
            }
        }

        sort(vc.begin()+ini, vc.end()+fin);
        return suma + derecha + izquierda;
    }
    return 0;


    //creo que sin utilizar la funcion no va (probar caso ipad), ordeno depues de contar el cambio que deberia estar ss



}


bool casoDePrueba() {

    // Leer los datos de la entrada
    int c;
    cin >> c;
    if (c == 0) {
        return false;
    }
    vector<int> vc(c);
    for (int i = 0; i < c; i++) {
        cin >> vc[i];
    }
    int contador = 0;
    int p = cambios(vc, 0, c - 1, contador);
    cout << p << endl;
    return true;

} // casoDePrueba

int main() {

    while(casoDePrueba());

    return 0;

} // main

