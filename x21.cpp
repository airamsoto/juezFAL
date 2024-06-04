#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int calculaTramo(vector<int>& vc, int tam) {
    int inicio = 0, fin = 0, numPositivos = 0, mejorTramo = vc.size() + 1;

    while (fin < vc.size()) {
        if (vc[fin] == 1) {
            numPositivos++;
        }

        while (numPositivos == tam) {
            mejorTramo = min(mejorTramo, fin - inicio + 1);

            if (vc[inicio] == 1) {
                numPositivos--;
            }

            inicio++;
        }

        fin++;
    }

    return mejorTramo;
}

bool casoDePrueba() {
    int num, tam;
    cin >> num;

    if (num == -1) return false;
    else {
        vector<int> vc(num);
        for (int i = 0; i < num; i++) {
            cin >> vc[i];
        }
        cin >> tam;
        int k = calculaTramo(vc, tam);
        cout << k << endl;
        return true;
    }
}

int main() {
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (casoDePrueba());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}
