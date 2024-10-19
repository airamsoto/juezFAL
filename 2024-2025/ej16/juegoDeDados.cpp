#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> encontrarMasRepetidos(int n, int maxValor, const vector<int>& tiradas) {
    vector<int> conteos(maxValor + 1, 0);
    for (int valor : tiradas) {
        conteos[valor]++;
    }
    int masRepeticiones = 0;
    for (int i = 1; i <= maxValor; i++) {
        masRepeticiones = max(masRepeticiones, conteos[i]);
    }
    vector<int> sol;
    for (int i = 1; i <= maxValor; i++) {
        if (conteos[i] == masRepeticiones) {
            sol.push_back(i);
        }
    }

    sort(sol.rbegin(), sol.rend());
    


    return sol;
}

bool resuelveCaso() {
    int n, maxValor;
    cin >> n >> maxValor;
    if (n == -1)
        return false;

    vector<int> tiradas(n);
    for (int i = 0; i < n; i++) {
        cin >> tiradas[i];
    }

    vector<int> resultado = encontrarMasRepetidos(n, maxValor, tiradas);
    for (int num : resultado) {
        cout << num << " ";
    }
    cout << "\n";
    return true;
}

int main() {
#ifndef DOMJUDGE
    ifstream in("sample.in");
    cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    cin.rdbuf(cin.rdbuf()); 
#endif
    return 0;
}
