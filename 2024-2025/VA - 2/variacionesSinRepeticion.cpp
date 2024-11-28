#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

void resolver(vector<char> &letras, vector<char> &sol, vector <bool> &usados, int k, int m) {
    for (int letra = 0; letra < m; letra++) {
        if(!usados[letra]) {         

            usados[letra] = true;
            sol[k] = letras[letra];

            if(k == sol.size() - 1) {
                for (int i = 0; i < sol.size(); i++) {
                   cout << sol[i];
                }
                cout << '\n';

            } else resolver(letras, sol,usados, k + 1, m);

            usados[letra] = false;
        }
            
            
            
    }
    
}
bool resuelveCaso() {

    int m, n; //siendo m el numero de letras y n el tamañao de la palabra
    cin >> m >> n;
    //Se consideran ´unicamente las letras del alfabeto anglosaj´on, cogi´endose las m primeras. Se garantiza que n <= m.
    if(!cin) return false;
    /*
    Para caso de prueba m = 3 y n = 2
ab
ac
ba
bc
ca
cb  */
    vector<char> letras(m);
    for (int i = 0; i < m; i++) {
        letras[i] = 'a' + i;
    }
    vector<char> palabra(n);
    vector<bool> usados (m, false);
    resolver(letras, palabra,usados, 0, m);
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

