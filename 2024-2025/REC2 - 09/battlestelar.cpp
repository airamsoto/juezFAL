#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


int nave(vector<int>& v,int inicio, int final) {
    if (inicio >= final) return 0;

    int medio = (inicio + final) / 2;
    int izq = nave(v, inicio, medio);
    int der = nave(v, medio + 1, final);

    int i = inicio;
    int j = medio + 1;
    int cont = 0;

    while (i <= medio && j <= final) {
        if (v[i] > v[j]) {
            cont += (medio - i + 1);
            j++;
        }
        else {
            i++;
        }
    }
    sort(v.begin() + inicio, v.begin() + final + 1);

    return izq + der + cont;
}


bool resuelveCaso() {
    int N;
    cin >> N;
    if (!cin)  
        return false;
    vector<int> v(N);
    for (int& i : v) cin >> i;
    cout << nave(v, 0, v.size() - 1) << endl;
    
    return true;
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
