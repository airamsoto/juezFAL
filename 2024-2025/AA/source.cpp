#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


bool resuelveCaso() {
    int n, l;
    cin >> n >> l;
    if (n == 0 && l == 0) return false;
    vector<int> v (n);
    vector<int> sol;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int contador = 1, segmentos = 0;
    for (int i = 1; i < n; i++) {

    
    
       if(abs(v[i] - v[i-1]) <= 1) {
            contador++;
        } else contador = 1;
        if(contador == l) {
            sol.push_back(i - l +1);
            segmentos++; 
        }
    }

    cout << segmentos << " ";
    for (int i = 0; i < sol.size(); i++)
    {
        cout << sol[i] << " ";
    }
    cout << '\n';
    

    
    
    
    
    return true;
    
} 



int main() {
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

 while (resuelveCaso()) {}
  
  
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}
