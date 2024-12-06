#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
/*
Comprobar relaciones y como incrementar el numero de canoas usadas una vez hay que pasar a la siguiente

*/
bool esValida (const vector <int>& personasPorCanoa, const vector<int> pesoActual, int canoa, const vector<int>& pesos, int k, int pesoMaximo,  vector<vector<int>> &sol) {
    bool jose = true;

    //falta comprobar lo de las relaciones
    for (int i = 0; i < pesos.size(); i++)
    {
        for (int j = 0; j < pesos.size(); j++) {
            
        }
    }
    
    return personasPorCanoa[canoa] < 3 && pesoActual[canoa] + pesos[k] <= pesoMaximo;
}
void canoas (const vector <int> &pesos, const vector<vector<int>> &relas, vector<int>& pesoActual, int &numeroCanoasActual, 
int k, int amigos,vector<int> &personasPorCanoa, int nCanoas, int pesoMaximo, int &canoasMinimas, vector<vector<int>> &sol) {
    for(int canoa = 0; canoa < nCanoas; canoa++) {
        if(esValida(personasPorCanoa, pesoActual, canoa, pesos, k, pesoMaximo, sol)) {
                pesoActual[canoa] += pesos[k];

                if(k == sol.size() -1) {
                    canoasMinimas = min (canoasMinimas, numeroCanoasActual);

                } else canoas (pesos, relas, pesoActual, numeroCanoasActual, k +1, amigos, personasPorCanoa, nCanoas, pesoMaximo, canoasMinimas, sol);
                pesoActual[canoa] -= pesos[k];
        }
        

    }
}

void resuelveCaso() {
    int amigos, canoas, pesoMaximo;
    cin >> amigos >> canoas >> pesoMaximo;
    vector <int> pesos (amigos);
    for (int i = 0; i < amigos; i++)
    {
        cin >> pesos[i];
    }
    
    vector <vector<int>> relas (amigos, vector<int> (amigos));
    for (int i = 0; i < amigos; i++)
    {
        for (int j = 0; j < amigos; j++)
        {
            cin >> relas[i][j];
        }
        
    }
    int pesoActual = 0, numeroCanoasActual = 0, mejorCanoas = INT_MAX;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int nCasos;
    cin >> nCasos;
    for (int i = 0; i < nCasos; i++)
    {
        resuelveCaso();
    }
    
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}
