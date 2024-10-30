#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

//devuelve el numero de parejas de numeros con diferencia en valor absoluto igual a k, así mismo, todo número está 0-emparejado consigo mismo.
int kemparejados(const vector<int> &v, int n, int k) {
    //el coste del algoritmo debe ser O(n)
    int cont = 0;

    if (k == 0) {
        return n;
    }

    int i = 0, j = 1;
    while (j < n) {
        int diff = v[j] - v[i];
        if (diff == k) {
            cont++;
            i++;
            j++;
        } else if (diff < k) {
            j++;
        } else {
            i++;
        }
        if (i == j) { //comprobar si sobraria este caso
            j++;
        }
    }

    return cont;
}
bool resuelveCaso() {
    int n, k;
    cin >> n;
    if(n == -1) return false;
    cin >> k;
    vector<int> v(n);
    for ( int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << kemparejados(v, n, k) << '\n';
    return true;
    
}

int main() {
#ifndef DOMJUDGE
    ifstream in("sample.in");
    cin.rdbuf(in.rdbuf());
#endif

   while (resuelveCaso()){}
#ifndef DOMJUDGE
    cin.rdbuf(cin.rdbuf()); 
#endif
    return 0;
}
