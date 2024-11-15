#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mejorTramo (const vector <int> &v, int L) {
    int contadorPaginas = 0, valoracionActual = 0, valoracionMaxima = 0;
    int inicio = 0;
    for (int i = 0; i < v.size(); ++i) {
      contadorPaginas++;
      valoracionActual+=v[i];
      if (contadorPaginas == L) {
        if(valoracionActual >= valoracionMaxima) {
            valoracionMaxima = valoracionActual;
            inicio = i - L + 1;
        }
    
        valoracionActual -= v[i - L + 1];
        contadorPaginas--;
      }
    }
    return inicio;
}


bool resuelveCaso() {
    int n, L;
    cin >> n >> L;
    if (n == 0 && L == 0) return false;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int inicio = mejorTramo(v, L);
    cout << inicio  << '\n';
    
    return true;
}

int main() {
#ifndef DOMJUDGE
    ifstream in("sample.in");
    cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso()) {}

#ifndef DOMJUDGE
    cin.rdbuf(cin.rdbuf());
#endif

    return 0;
}
