
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



int esPastoso(vector <int> v) {
    int suma = 0;
    for (int i = v.size() -1; i >= 0; --i) {
        if(v[i] == suma) return i;
        else suma+=v[i];

    }

    return -1;
}


void resuelveCaso() {
    int num;
    cin >> num;
    vector <int> vc(num);
    for (int i = 0; i < num; i++) {
        cin >> vc[i];

    }
    int i = esPastoso(vc);
    if (i == -1) cout << "No" << '\n';
    else cout << "Si " << i << '\n';

}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


    int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);

#endif

    return 0;
}