#include <iostream>
#include <vector>
#include <fstream>



using namespace std;

bool bingo (const vector<int> &vc, int inicio, int final, int numero, int&es) {
    if(inicio == final) {
        return false;
    } else {
        int medio = (final + inicio) / 2;
        if(vc[medio] == medio + numero) {
            es = vc[medio];
            return true;
        }
        else if(vc[medio] > numero + medio) {
            return bingo(vc, inicio, medio, numero,es);
        } else {
            return bingo(vc, medio+1, final, numero,es);
        }
    }


}







void resuelveCaso() {
    int f, numero;
    cin >> f;
    cin >> numero;
    vector<int> vc (f);
    for (int i = 0; i < f; ++i) {
        cin >> vc[i];

    }
    int jose = 0;
    if( !bingo(vc, 0, vc.size(), numero, jose)) cout << "NO";
    else cout << jose;
    cout << endl;

}

int main() {
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    // Elimina la línea system("pause") para evitar problemas en algunos entornos
#endif

    return 0;
}