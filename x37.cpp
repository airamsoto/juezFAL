#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


void segmentosConsecutivos (const vector<int> &v) {
    long long int contador = 0, longitud = 1;
    for (int i = 1; i < v.size(); i++) {
        if (abs(v[i] - v[i - 1]) == 1) {
            longitud++;
            if (longitud >= 2) {
                contador += longitud - 1;
            }
        }
        else {
            longitud = 1;
        }
    }

    cout << contador << endl;

}



void resuelveCaso() {
    int n;
    cin >> n;
    vector<int> v (n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    segmentosConsecutivos(v);


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
