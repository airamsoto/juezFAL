#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
//un vector es creciente pro los por los cuando la diferencia es de 1 y es creciente
//un vector es divertido si un numero no se repite mas de diff veces
bool crecientePorLosPelos (const vector<int>&v, int diff) {
    int i = 0, j = 1;
    vector<int> repetidos(1000, 0);//inicializo a 1000 elementos porque es el maximo que puede tener el vector (segun el enunciado)
    bool crecienteYDivertido = true;
   repetidos[v[i]]++;
    while (j < v.size() && crecienteYDivertido) {
        repetidos[v[j]]++;
        if(repetidos[v[j]] > diff) {
            crecienteYDivertido = false;
        }
        if (v[j] - v[i] < 0 || v[j] - v[i] > 1) {
            crecienteYDivertido = false;
        }
        i++;
        j++;
    }
    return crecienteYDivertido;

}

void resuelveCaso() {
    int n, diff;
    cin >> diff >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    if(crecientePorLosPelos(v, diff)) {
        cout << "SI\n";
    } else {
        cout << "NO\n";
    }

   
    
}

int main() {
#ifndef DOMJUDGE
    ifstream in("sample.in");
    cin.rdbuf(in.rdbuf());
#endif

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    resuelveCaso();
  }
#ifndef DOMJUDGE
    cin.rdbuf(cin.rdbuf()); 
#endif
    return 0;
}