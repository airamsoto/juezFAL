#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
//airam martin soto E37
using namespace std;

/*
 * n = v.size()
 * P{suma = 0, numero = 0, v.size() >= 0}
 * proc encuestas(vector<int>& v, long long int&suma, int& numero)
 * Q{contador = n - #e, suma = sumatorio Vu (0<u<=n-e) : v[u]}
 *
 * invariante: 1<=i<v.size(), contador = n - #e, suma = sumatorio Vu (0<u<=n-e) : v[u]
 * e : 0 <= n ^ minimo
 * cota = n - i
 */

void encuestas(vector<int>& v, long long int&suma, int& numero) {
    int minimo = v[0];
    int contador = 1;
    for (int i = 1; i < v.size(); ++i) {
        if(v[i] == minimo) contador++;
        else if(v[i] < minimo) {
            suma += contador*minimo;
            numero+=contador;
            contador = 1;
            minimo = v[i];
        } else {
            suma+=v[i];
            numero++;
        }


    }
}
void resuelveCaso() {
    int n, aux;
    cin >>n;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        cin >> aux;
        v.push_back(aux);
    }

    long long int suma = 0;
    int contador = 0;

    encuestas(v, suma, contador);

    cout << suma << " " <<contador << '\n';



}


int main() {
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
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
}//
// Created by airam on 03/06/2024.
//
