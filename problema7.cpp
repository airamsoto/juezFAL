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
long long int ignorarMinimo (const vector<long long int> &v,int n, int&sumados) {
    long long int suma = 0, minimo = v[0];
    int contador = 0;
    for (int i = 0; i < n; ++i) {
        if(minimo == v[i]) contador++;
        else if (v[i] < minimo){
            minimo = v[i];
            contador = 1;
        }
        suma+=v[i];
        sumados++;

    }
    sumados-=contador;
    return suma-(minimo*contador);
}
void resuelveCaso() {
    int n;

    cin >> n;
    vector<long long int> vc(n);

    for (int i = 0; i < n; i++) {
        cin >> vc[i];
    }

    int sumados = 0;
    cout << ignorarMinimo(vc, n, sumados) << " " << sumados << '\n';


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