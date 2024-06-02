#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool esCaucasico (const vector<int> &vc, int inicio, int final) {
    if (inicio == final -1) {
        if (vc[inicio] % 2 == 0) {
            return 1;
        } else {
            return 0;
        }
    }
    else {
        int medio = (final + inicio) / 2;
        int izq = 0;
        int der = 0;
        izq+= esCaucasico(vc, inicio, medio);
        der+= esCaucasico(vc, medio, final);

        if(abs(izq - der) > 2) return false;
        else return true;

    }


}

bool resuelveCaso() {
    int f;
    cin >> f;
    if (f == 0)
        return false;

    vector<int> vc (f);

    for (int i = 0; i < f; ++i) {
        cin >> vc[i];
    }
    if(esCaucasico(vc, 0, vc.size())) cout << "SI"<< endl;
    else cout << "NO" << endl;




    return true;
}

int main() {
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    // Elimina la línea system("pause") para evitar problemas en algunos entornos
#endif

    return 0;
}
