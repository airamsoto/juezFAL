
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


bool esCaucasico(const vector<int>& vc, int inicio, int final, int& paresTotales) {
    if (inicio == final) {
        paresTotales = vc[inicio] % 2 == 0;
        return true;
    } else {
        int medio = (inicio + final) / 2;
        int paresIzq, paresDer;
        if (esCaucasico(vc, inicio, medio, paresIzq) && esCaucasico(vc, medio + 1, final, paresDer)) {
            paresTotales = paresIzq + paresDer;
            return abs(paresDer - paresIzq) <= 2;
        } else {
            return false;
        }
    }
}

bool resuelveCaso() {
    int f;
    cin >> f;
    if (f == 0)
        return false;

    vector<int> vc(f);

    for (int i = 0; i < f; ++i) {
        cin >> vc[i];
    }

    int paresTotales;
    if (esCaucasico(vc, 0, f - 1, paresTotales)) {
        cout << "SI" << endl;
    } else {
        cout << "NO" << endl;
    }

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
