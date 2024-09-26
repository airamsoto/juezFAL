// Airam Martin Soto

#include <stdio.h>
#include <iostream>
#include <fstream>
#include<algorithm>
#include <vector>

#include <climits>

using namespace std;



const int MAX = 50;


//Describe el espacio de soluciones: profundidad, ramificacion, tamaño
//Restricciones explicitas e implicitas
/*
* n = posiciones
* m = artistas
Espacio de soluciones: en un vector de enteros (sol) en el cual los niveles  (k) seran cada artista ordenadas en funcion de la matriz vetos
El arbol tiene una profundidad de n y de ramificacion m  de tamanio n^m
En cuanto a las restricciones, tenemos explicitas la que sigue la matriz de vetos la cual se basa en valores 1 y 0 indicando que artista puede o no puede tocar de otro



*/

//Implementa el algoritmo de vuelta atras. Explica los marcadores utilizados
//Utilizaremos un marcador en el que indicaremos si la posicion (orden en el que tocan) esta ocupada o no a traves de un vecotor de booleanos que inicializaremos a false

bool esValida(vector<bool>& marcadorPos, const vector <vector <int>> &vetos, vector<int>& sol, int posicion, int k) {
        if(k == 0 || (k!= 0 && vetos[posicion][sol[k-1]] == 1)) {
            return true;
        }

    return false;
}



void artistas(const vector <vector <int>> &donaciones, const vector <vector <int>> &vetos, vector<int>& sol, vector<int>& solmejor, int& donacionesTotales, int& donacionMejor, int k, int n, vector<bool>& marcadorPos, vector<int> &maxAcum) {
    for (int posicion = 0; posicion < n; posicion++) {
        if(!marcadorPos[posicion]) {
            if (esValida(marcadorPos, vetos, sol, posicion, k)) {
                sol[k] = posicion;
                marcadorPos[posicion] = true;
                donacionesTotales+= donaciones[posicion][k];



                if (k == n - 1) {

                    if (donacionMejor < donacionesTotales) {
                        donacionMejor = donacionesTotales;
                        solmejor = sol;
                    }
                } else {
                    int estimacion = donacionesTotales+maxAcum[k+1];
                    if( estimacion  > donacionMejor) {
                        artistas(donaciones, vetos, sol, solmejor, donacionesTotales, donacionMejor, k + 1, n, marcadorPos, maxAcum);
                    }

                }


                donacionesTotales -= donaciones[posicion][k];
                marcadorPos[posicion] = false;
            }
        }



    }
}

void maximos(vector<int>& maxAcum, int i, int j, vector<vector<int>>& donaciones) {
    maxAcum[j] = max(maxAcum[j], donaciones[i][j]);
}





//Plantea dos posibles funciones de poda de optimalidad, razona sobre cual de ellas es mejor
//e implementala
/*
La poda que vamos a implementar es calculando una estimacion que sera la suma de los maximo de la donacion de cada turno y a la hora de ver si es porometedora o no
*/



void resuelveCaso()
{

    int n;
    cin >> n;
    //int donaciones[MAX][MAX];
    vector <vector <int>> donaciones(MAX, vector<int> (MAX));
    vector<int> maxAcum(n, INT_MIN);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; ++j)
        {
            cin >> donaciones[i][j];
            //funcion que calcula maximos
           maximos (maxAcum, i, j, donaciones);
        }

    //int vetos[MAX][MAX];
    vector <vector <int>> vetos(MAX, vector<int> (MAX));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; ++j)
        {
            cin >> vetos[i][j];
        }
    vector <int> sol(n);
    vector <int> mejorSol(n);
    int donacionesTotales = 0, donacionMejor = INT_MIN;
    vector <bool> marcadorPos(n, false);

    for (int i = n-2; i>= 0; i--) { //revisar del problema de los funcionarios
        maxAcum[i]+=maxAcum[i+1];
    }

    artistas(donaciones, vetos, sol, mejorSol, donacionesTotales, donacionMejor, 0, n, marcadorPos, maxAcum);
    if (donacionMejor == INT_MIN) cout << "NEGOCIA CON LOS ARTISTAS";
    else cout << donacionMejor;
    cout << endl;




//Llama al algoritmo de vuelta atras
//Escribe en la salida el resultado.

}





int main() {
// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();

// restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}