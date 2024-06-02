#include <iostream>
#include <fstream>
#include <vector>
//airam martin soto E37
using namespace std;
/*
 * ESPECIFICACION:
 *
 *
 *
 *
 */
void mayorNumero (const vector<int> &v,int n, int &mayor, int& contador) {
    for (int i = 1; i < n-1; ++i) {
        if(v[i] > mayor) {
            mayor = v[i];
            contador = 1;
        } else if(v[i] == mayor) {
            contador++;
        }
    }
}
void resuelveCaso() {
    int n = -1;
    vector<int> v;
    while (n != 0) {
        cin >> n;
        v.push_back(n);
    }
    int mayor = v[0], contador = 1;
    mayorNumero(v, v.size(), mayor, contador);
    cout << mayor << " " << contador << '\n';


}

int main() {
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}