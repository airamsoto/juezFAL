#include <iostream>
#include <climits>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

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
        //todo haria falta ordenarlo
        return suma + derecha + izquierda;
    }
    return 0;

}


bool resuelveCaso() {
    int n;
    cin >> n;
    if(!cin) return false;
    vector<int> v (n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    cout << cambios (v, 0 , n-1, 0) << '\n';;


    return true;
}
int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    //system("pause");
#endif
    return 0;
}