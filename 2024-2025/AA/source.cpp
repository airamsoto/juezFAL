#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


bool resuelveCaso() {
    int n;
    cin >> n;
    if(n == -1) return 0;
    vector<int> v (n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<long long int> acumulados (n+1, 0);
    acumulados[n-1] = v[n-1];
    for (int i = n-2; i >= 0; --i)
    {
     acumulados[i] = acumulados[i+1] + v[i];
    }
    
    int p, pregunta;
    cin >> p;
    for (int i = 0; i < p; i++)
    {
      cin >> pregunta;
      cout << acumulados[pregunta-1] << '\n';
    }
    cout << "---\n";
    
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
