#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

bool esValida(vector<int> sol, int k, int i, vector<string> tipoJuguetes)
{
    if (k % 2 != 0)
    {
        if (tipoJuguetes[i] == tipoJuguetes[sol[k - 1]]) 
            return false;
        if (i < sol[k - 1])
            return false;
    }
    return true;
}

void juguetes(int m, int n, int k, vector<string> tipoJuguetes, bool &haySol, vector<int> &sol)
{

    for (int i = 0; i < m; i++)
    {

        sol[k] = i;

        if (esValida(sol, k, i, tipoJuguetes))
        {

            if (k == (n * 2) - 1)
            {
                for (int i = 0; i < sol.size(); i++)
                {
                    cout << sol[i] << " ";
                }
                cout << "\n";
                haySol = true;
            }
            else
            {
                juguetes(m, n, k + 1, tipoJuguetes, haySol, sol);
            }
        }
    }
}

bool resuelveCaso()
{
    int m, n;
    cin >> m >> n;
    if (!cin)return false;
    vector<string> tipoJuguete(m);
    for (int i = 0; i < m; i++)
    {
        cin >> tipoJuguete[i];
    }

    bool haySol = false;
    vector<int> sol(n * 2);
    juguetes(m, n, 0, tipoJuguete, haySol, sol);

    if (!haySol) cout << "SIN SOLUCION\n";
    cout << "\n";
    return true;
}

int main()
{

#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    while (resuelveCaso());
#ifndef DOMJUDGE 
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}