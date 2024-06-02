#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int presoFugado (vector <char> const&vc, char ini, char fin, int inicio, int final) {
    if(inicio == final -1) {
        if(vc[inicio] == ini) return fin;
        else return ini;
    } else {
        int medio = (inicio + final) /2;
        char presoMedio = (ini + fin) / 2;
        if(vc[medio]  > presoMedio) return presoFugado(vc, ini, presoMedio, inicio, medio);
        return presoFugado(vc, presoMedio, fin, medio, final);
    }

}



bool resuelveCaso() {
    char ini, fin;

    cin >> ini >> fin;

    int num = fin - ini;

    vector<char> vc(num);
    for (int i = 0; i < num; i++) {
        cin >> vc[i];
    }

    char p = presoFugado(vc, ini, fin, 0, vc.size());
    cout << p << endl;

    return true;
}

int main() {
    // Ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; i++) {
        resuelveCaso();
    }

    // Restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}
