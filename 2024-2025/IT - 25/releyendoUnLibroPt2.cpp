#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int tramoConElMaximoValor(const vector<int> &v, int L) {
    int n = v.size(), valorMasAlta = *max_element(v.begin(), v.end()), sumaActual = 0, sumaMaxima = -1;
    int contadorDePaginas = 0, mejorInicio = 0, contadorMaximos = 0;
    for (int i = 0; i < n; ++i) {
        sumaActual += v[i]; 
        contadorDePaginas++;
        if (v[i] == valorMasAlta) contadorMaximos++;
        if (contadorDePaginas > L) {
            if (v[i - L] == valorMasAlta) contadorMaximos--; 
            sumaActual -= v[i - L];
            contadorDePaginas--;
        }
        if (contadorDePaginas == L && contadorMaximos > 0 && sumaActual >= sumaMaxima) {
            sumaMaxima = sumaActual;
            mejorInicio = i - L + 1;
        }
        
    }
    return mejorInicio;
}

bool resuelveCaso() {
    int n, L;
    cin >> n >> L;
    if (n == 0 && L == 0) return false;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int inicio = tramoConElMaximoValor(v, L);
    cout << inicio << '\n';

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
