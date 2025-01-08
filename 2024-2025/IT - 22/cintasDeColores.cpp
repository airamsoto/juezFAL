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
    if(!cin) return false;
    vector<int> azules;
    vector<int> verdes;
    vector<int> rojos;
    char aux;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        cin >> num;
        switch (aux) {
            case 'r': {
                rojos.push_back(num);
            }
            break;
            case 'a': {
                azules.push_back(num);
            }
            break;
            case 'v': {
                verdes.push_back(num);
            }
            break;
        }
    }

    sort (azules.begin(), azules.end());
    sort (rojos.begin(), rojos.end());
    sort (verdes.begin(), verdes.end());

    cout << "Azules: ";
    for (int i = 0; i < azules.size(); i++)
    {
        cout << azules[i] << " ";
    }
    cout << '\n';

    cout << "Verdes: ";
    for (int i = 0; i < verdes.size(); i++)
    {
        cout << verdes[i] << " ";
    }
    cout << '\n';

    cout << "Rojas: ";
    for (int i = 0; i < rojos.size(); i++)
    {
        cout << rojos[i] << " ";
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
