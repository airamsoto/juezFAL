#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


bool resuelveCaso()
{
    int n, alturaMinima, altura;
    cin >> n >> alturaMinima;
    if (!cin)
        return false;
    vector<string> bajos, altos;
    string nombre;

    for (int i = 0; i < n; i++)
    {
        cin >> nombre >> altura;
        if (altura <= alturaMinima)
        {
            bajos.push_back(nombre);
        }
        else
        {
            altos.push_back(nombre);
        }
    }

    sort(bajos.begin(), bajos.end());
    sort(altos.begin(), altos.end());

    cout << "Bajos:";
    for (const auto &nombre : bajos)
    {
        cout << " " << nombre;
    }
    cout << "\nAltos:";
    for (const auto &nombre : altos)
    {
        cout << " " << nombre;
    }
    cout << "\n";

    return true;
}

int main()
{
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("sample.in");
    cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

#ifndef DOMJUDGE
    cin.rdbuf(cin.rdbuf());
#endif

    return 0;
}
