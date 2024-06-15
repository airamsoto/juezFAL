#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

char presoFugado (const vector<char> &v, char letraIni, int ini, int fin) {
    if(ini == fin) {
        if(v[ini] - letraIni == ini) return v[ini]  + 1;
        else return v[ini] - 1;


    } else {
        int m = (ini + fin) / 2;
        char letraMedio = v[m];
        if(letraIni + m  == letraMedio) {
            return presoFugado(v, letraIni, m+1, fin);
        } else return presoFugado(v, letraIni, ini, m);
    }
}
void resuelveCaso() {
    char letraIni, letraFin;
    cin >>letraIni >> letraFin;

    vector<char> v (letraFin -letraIni);
    for (int i = 0; i < v.size(); ++i) {
        cin >> v[i];
    }

    cout << presoFugado(v, letraIni, 0, v.size()-1) << '\n';



}


int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int nCasos;
    cin >> nCasos;
    for (int i = 0; i < nCasos; ++i) {
        resuelveCaso();
    }

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);//system("pause");
#endif
    return 0;
}
