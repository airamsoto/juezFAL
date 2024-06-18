#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

char letraFugada (const vector<char>& v, int ini, int fin, char letraIni) {
    if(ini == fin - 1) {
        if(letraIni + ini != v[ini]) return v[ini] -1;
        else return v[ini] +1;

    } else {
        int m = (ini + fin) / 2;
        if (v[m] != m + letraIni) {
            return letraFugada(v, ini, m, letraIni);
        } else {
            return letraFugada(v, m, fin, letraIni);
        }
    }
}





void resuelveCaso() {
char letraIni, letraFin;
cin >> letraIni >> letraFin;

vector<char> v (letraFin - letraIni);

    for (int i = 0; i < v.size(); ++i) {
        cin >> v[i];
    }

    cout << letraFugada (v, 0, v.size(), letraIni)<< '\n';;


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
