#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <numeric>
#include <algorithm>
using namespace std;


bool esExtranyo (const vector <int> &v, int ini, int fin) {
    if(ini == fin -1) {
        return true;
    } else {
        int mitad = (ini+ fin) / 2;
        int sumaIzq = 0, prodIzq = 1;
        for (int i = ini; i < mitad; i++) {
            if(v[i] % 2 == 0) {
                sumaIzq += v[i];
            } else {
                prodIzq *= v[i];
            }
        }
        int sumaDer = 0, prodDer = 1;
        for (int i = mitad; i < fin; i++) {
            if(v[i] % 2 != 0) {
                sumaDer += v[i];
            } else {
                prodDer *= v[i];
            }
        }
        return sumaIzq + prodIzq <= sumaDer + prodDer && (esExtranyo(v, ini, mitad) || esExtranyo(v, mitad, fin));
    }
}


void resuelveCaso() {
    int n;
    cin >> n; 
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if(esExtranyo(v, 0, n)) {
        cout << "SI" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("sample.in");  //o cambia el nombre por el fichero que te descargues
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int nCasos;
    cin >> nCasos;
    for (int i = 0; i < nCasos; i++) {
        resuelveCaso();
    }
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
   
#endif

    return 0;
}

