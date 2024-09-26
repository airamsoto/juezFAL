#include <iostream>
#include <vector>

using namespace std;

int encontrarDefecto(const vector<char>& v, int inicio, int fin) {
    if (inicio == fin) {
        return inicio;
    }

    int medio = inicio + (fin - inicio) / 2;

    for (int i = inicio; i <= medio; ++i) {
        if (v[i] == '*') {
            return encontrarDefecto(v, inicio, medio);
        }
    }
    return encontrarDefecto(v, medio + 1, fin);
}

bool resuelveCaso() {
    int n;
    cin >> n;
    if (n == -1) return false;

    vector<char> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int posicion = encontrarDefecto(v, 0, n - 1);
    cout << posicion << endl;

    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}

