
#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

/*
No le gusta el color verde, asi que nunca coloca
dos piezas verdes juntas, ni permite que el n´umero de piezas verdes supere al de piezas azules en ning´un
momento mientras se va construyendo la torre. Adem´as, como el color rojo es su favorito, las torres que
construye siempre tienen en la parte inferior una pieza roja, y en la torre final el n´umero de piezas rojas
debe ser mayor que la suma de las piezas azules y verdes.


*/
bool esValida(vector<int> &sol, int k, int color, vector<int> &usados) {
    if (k > 0 && sol[k - 1] == 2 && color == 2) return false;
    if (usados[2] > usados[0]) return false;
    if (usados[1] + sol.size() - 1 - k <= usados[0] + usados[2]) return false;
    return true;

}

void torres(vector<int> &sol, int k, vector<int> &colores, vector<int> &usados, bool &exito) {
    for (int color = 0; color < 3; ++color) {

        if (colores[color] > 0) {
            sol[k] = color;
            colores[color]--;
            usados[color]++;
            if (esValida(sol, k, color, usados)) {
                if (k == sol.size() - 1) {
                    exito = true;
                    for (int i : sol) {
                        switch (i) {
                            case 0:
                                cout << "azul";
                                break;
                            case 1:
                                cout << "rojo";
                                break;
                            case 2:
                                cout << "verde";
                                break;
                        }
                        cout << " ";
                    }
                    cout << '\n';


                } else {
                    torres(sol, k + 1, colores, usados, exito);
                }
            }
            colores[color]++;
            usados[color]--;

        }


    }
}

bool resuelveCaso() {
    int numero;
    cin >> numero;

    if (numero == 0) return false;


    vector<int> colores(3);
    for (int i = 0; i < 3; ++i) {
        cin >> colores[i];

    }
    vector<int> sol(numero); //vector de soluciones de altura numero
    vector<int> usados(3, 0);
    sol[0] = 1;
    usados[1]++;
    colores[1]--;
    bool jose = false;
    torres(sol, 1, colores, usados, jose);
    if (!jose) cout << "SIN SOLUCION" << '\n';
    cout << '\n';


    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("sample.in");  //o cambia el nombre por el fichero que te descargues
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    while (resuelveCaso()) {}
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
   
#endif

    return 0;
}

