#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Implementa la función recursiva
pair<int, bool> extranio(const vector<int>& vc, int inicio, int final) {
    if (inicio == final - 1) {
        return {vc[inicio], true};
    } else {
        int medio = (inicio + final) / 2;

        pair<int, bool> resultIzq = extranio(vc, inicio, medio);
        pair<int, bool> resultDer = extranio(vc, medio, final);

        int sumaParesIzq = 0, prodImparesIzq = 1, prodParesDer = 1, sumImparesDer = 0;

        if (resultIzq.first % 2 == 0) {
            sumaParesIzq += resultIzq.first;
        } else {
            prodImparesIzq *= resultIzq.first;
        }

        if (resultDer.first % 2 == 0) {
            prodParesDer *= resultDer.first;
        } else {
            sumImparesDer += resultDer.first;
        }


        bool resultado = (sumaParesIzq + prodImparesIzq) <= (prodParesDer + sumImparesDer) && (resultIzq.second || resultDer.second);

        return {sumaParesIzq + prodImparesIzq + prodParesDer + sumImparesDer,resultado && (resultIzq.second || resultDer.second) };
    }
}

// Analisis justificado del coste de esta funcion recursiva: recurrencia y coste asintótico.

bool resolver(vector<int> const& v) {
    pair<int, bool> resultado = extranio(v, 0, v.size());
    return resultado.second;
}

void resuelveCaso() {
    int n = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    if (resolver(v))
        cout << "SI\n";
    else
        cout << "NO\n";
}

int main() {
    // Para la entrada por fichero
#ifndef DOMJUDGE
    ifstream in("casos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
