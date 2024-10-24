#include <fstream>
#include <iostream>
#include <vector>
using namespace std;


int consecutivos (const vector<int> &v) {
    if(v.size() == 0) return 0;
    int contador = 1, masLargo = 1;

    for (int i = 0; i < v.size() -1; i++)
    {
        if(abs(v[i] - v[i+1]) == 1){
        
            contador++;
            
        } else contador = 1;
        masLargo = max(masLargo, contador);
    }
    return masLargo;
    
}
void resuelveCaso() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

   cout << consecutivos(v) << '\n';
}

int main() {
#ifndef DOMJUDGE
    ifstream in("sample.in");
    cin.rdbuf(in.rdbuf());
#endif

   int n;
   cin >> n;
   for (int i = 0; i < n; i++)
   {
       resuelveCaso();
   }
#ifndef DOMJUDGE
    cin.rdbuf(cin.rdbuf()); 
#endif
    return 0;
}
