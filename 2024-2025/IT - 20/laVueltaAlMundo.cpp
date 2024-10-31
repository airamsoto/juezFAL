#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
long long int kilometrosQuedan(vector<long long int>& v, int n, int d, long long int suma) {
    if (d == 0) return suma;
    else if (d == n + 1) return 0;
    return suma - v[d - 1];
}

bool resuelveCaso() {
    int n;
    cin >> n;
    if (n == -1) return false;

    vector<long long int> v(n);
    long long int sumatorio = 0;
    int val;

    for (int i = 0; i < n; i++) {
        cin >> val;
        sumatorio += val;
        v[i] = sumatorio;
    }

    int p, d;
    cin >> p;
    for (int i = 0; i < p; i++) {
        cin >> d;
        long long int sol = kilometrosQuedan(v, n, d - 1, sumatorio);
        cout << sol << "\n";
    }
    cout << "---\n";

    return true;
}

int main() {
#ifndef DOMJUDGE
    ifstream in("sample.in");
    cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso()) {}
#ifndef DOMJUDGE
    cin.rdbuf(cin.rdbuf());
#endif
    return 0;
}
