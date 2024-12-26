#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void papaNoel2 (const vector <vector<int>>& satisfacciones,  vector <bool>& marcador , vector <int> &sol, int &satisfaccionActual , int &mejorSatisfaccion, int k, int m, int n) {
    for (int regalo = 0; regalo < m; regalo++) {
        if(!marcador[regalo]) {
            marcador[regalo] = true;
            satisfaccionActual+=satisfacciones[k][regalo];
            sol[k] = regalo;
            if(k == n-1) {
                mejorSatisfaccion = max(mejorSatisfaccion, satisfaccionActual);
            } else papaNoel2 (satisfacciones, marcador, sol, satisfaccionActual, mejorSatisfaccion, k+1, m, n);

            marcador[regalo] = false;
            satisfaccionActual-=satisfacciones[k][regalo];
        }
    }
}

bool resuelveCaso() {
    int m, n; //m juguetes, n ninios
    cin >> m >> n;
    if(!cin) return false;

    vector <vector<int>> satisfacciones (n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> satisfacciones[i][j];
        }
        
    }
    
    vector <bool> marcador (m, false);
    vector <int> sol (n);
    int satisfaccionActual  = 0, mejorSatisfaccion = -1;
    papaNoel2 (satisfacciones, marcador, sol, satisfaccionActual, mejorSatisfaccion,0, m, n);

    cout << mejorSatisfaccion << '\n';
    
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

