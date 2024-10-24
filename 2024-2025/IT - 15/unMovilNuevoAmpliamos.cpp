#include <iostream>
#include <fstream>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> movilNuevo(const vector<int> &a, const vector<int> &b)
{
    unordered_set<int> cjt;
    vector<int> sol;
    for (int i = 0; i < a.size(); i++)
    {

        sol.push_back(a[i]);
    }
    for (int i = 0; i < b.size(); i++)
    {
        sol.push_back(b[i]);
    }

    sort(sol.begin(), sol.end());
    auto last = unique(sol.begin(), sol.end());
    sol.erase(last, sol.end());
    return sol;
}
void resuelveCaso()
{
    int nA, nB, aux;
    cin >> nA >> nB;
    vector<int> a(nA);
    vector<int> b(nB);

    for (int i = 0; i < a.size(); i++)
    {
        cin >> aux;
        a[i] = aux;
    }
    for (int i = 0; i < b.size(); i++)
    {
        cin >> aux;
        b[i] = aux;
    }

    vector<int> sol = movilNuevo(a, b);
    for (int i = 0; i < sol.size(); i++)
    {
        cout << sol[i] << " ";
    }
    cout << "\n";
}

int main()
{
    // ajuste para que cin extraiga directamente de un fichero
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
