#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

bool divertida(const vector<int>& a, int n) {
    int sum = 0;
    int totalSum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (sum < 0) {
            return false;
        }
        totalSum += a[i];
    }

    return totalSum == 0;
}


bool resuelveCaso() {
  int n;
  cin >> n;
  if (n == -1) return false;

  vector<int> v (n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    if (divertida(v, n)) {
        cout << "SI" << endl;
    } else {
        cout << "NO" << endl;
    }
    return true;


}


int main() {
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

 while(resuelveCaso()) {

 }

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    //system("pause");
#endif
    return 0;
}
