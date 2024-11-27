#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

void resolver(vector<char> &letras, vector<char> &palabra, int n, int m) {
    for (int i = 0; i < m; i++) {              
            palabra[n] = letras[i];
            if(n == palabra.size() - 1) {
                for (int i = 0; i < palabra.size(); i++) {
                   cout << palabra[i];
                }
                cout << '\n';
            } else resolver(letras, palabra, n + 1, m);
    }
    
}
bool resuelveCaso() {

    int m, n; //siendo m el numero de letras y n el tamañao de la palabra
    cin >> m >> n;
    //Se consideran ´unicamente las letras del alfabeto anglosaj´on, cogi´endose las m primeras. Se garantiza que n <= m.
    if(!cin) return false;
    /*
    Para caso de prueba m = 3 y n = 2
aa
ab
ac
ba
bb
bc
ca
cb
cc
    
    */
    vector<char> letras(m);
    for (int i = 0; i < m; i++) {
        letras[i] = 'a' + i;
    }
    vector<char> palabra(n);
    resolver(letras, palabra, 0, m);
    cout << '\n';


    return true;

}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("sample.in");  //o cambia el nombre por el fichero que te descargues
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    while (resuelveCaso()) {}
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
   
#endif

    return 0;
}

