
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



bool estaParcialmenteOrdenado(vector<int> const& vc, int inicio, int fin, int& maximo, int& minimo) {

    if (inicio  == fin - 1) {
        maximo = minimo = vc[inicio];
        return true;
    }
    int m = (fin+inicio) /2, maxIzq, minIzq, maxDer, minDer;
    bool izquierdaOrdenada = estaParcialmenteOrdenado(vc, inicio, m, maxIzq, minIzq);
    bool derechaOrdenada = estaParcialmenteOrdenado(vc, m, fin, maxDer, minDer);
    maximo = max(maxIzq, maxDer);
    minimo = min(minIzq, minDer);
    return (maxDer >= maxIzq &&  minIzq<= minDer) && izquierdaOrdenada && derechaOrdenada;
}


bool resuelveCaso() {

    int num;
    cin >> num;
    if(num == 0) return false;
    vector <int> vc;
    while (num != 0) {
        vc.push_back(num);
        cin >> num;
    }
    int minimo, maximo;
    int jose = estaParcialmenteOrdenado(vc, 0, vc.size(), minimo,maximo);
    if (jose) cout << "SI";
    else cout << "NO";
    cout << endl;
    return true;
}

int main() {
    // Ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    while (resuelveCaso());
    // Restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}


