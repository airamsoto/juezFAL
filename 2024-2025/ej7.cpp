#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
//airam martin soto 
using namespace std;

void encuestas (const vector <long long int> &v) {
    long long minimo = v[0], contador = 0, minimosContador = 1, suma = 0;
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] <= minimo) {
            if(minimo == v[i]) minimosContador++;
            else {
                suma += (minimo * minimosContador);
                contador += minimosContador;
                minimo = v[i];
                minimosContador = 1;
            }
        } else {
            contador++;
            suma += v[i];
        }
    }
    cout << suma << " " << contador << '\n';
}
void resuelveCaso() {
    int n;
    cin >> n;
    vector<long long int> v (n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    encuestas(v);



}


int main() {
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        resuelveCaso();
    }

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}