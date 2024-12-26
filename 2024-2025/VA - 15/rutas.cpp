#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool esValida (const vector <vector<int>> &datos, vector <int> &sol, int k, int ruta) {
    if(k < 1) return true;
    if (k == 1 && datos[ruta][sol[k-1]] == 1) return false;
    if (k >= 2 && (datos[ruta][sol[k-1]] == 1 || datos[ruta][sol[k-2]] == 1)) return false;
    return true;
}

void vueltaAtrasRutas (const vector <vector<int>> &datos, vector <int> &sol, vector <int> &mejorSol, vector <bool> &usada, int &satisfaccionActual, int &mejorSatisfaccion, int k, int n, const vector<int> &satisfacciones, int x) {
    for(int ruta = 0; ruta < n; ruta++) {
        if(sol[0] == 1 && ruta == 0) {
           // cout<< "QUESITO";
        }
        if(!usada[ruta]) {
            if(esValida(datos, sol, k, ruta)) {
                sol[k] = ruta;
                usada[ruta] = true;
                satisfaccionActual+= satisfacciones[ruta];
                if(k == x -1) {
                    if(satisfaccionActual > mejorSatisfaccion) {
                        mejorSatisfaccion = satisfaccionActual;
                        mejorSol = sol;
                    } else if (satisfaccionActual == mejorSatisfaccion) {
                        for(int i = 0; i < sol.size(); i++) {
                            if(sol[i] < mejorSol[i]) {
                                mejorSol = sol;
                                break;
                            }
                            else if(sol[i] > mejorSol[i]) {
                                break;
                            }
                        }
                    }

                } else vueltaAtrasRutas(datos, sol, mejorSol, usada, satisfaccionActual, mejorSatisfaccion, k+1, n, satisfacciones, x);

                usada[ruta] = false;
                satisfaccionActual-= satisfacciones[ruta];
            }
        }
    }
}
void resuelveCaso() {
    int n, x; //siendo n las rutas y x los dias de planificacion
    cin >> n >> x;
    vector <vector<int>> datos (n, vector<int> (n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> datos[i][j];
        }
        
    }
    vector<int> satisfacciones (n);
    for (int i = 0; i < n; i++)
    {
        cin >> satisfacciones[i];
    }
    
    
    vector <int> sol (x, -1);
    vector <int> mejorSol (x, -1);
    int satisfaccionActual = 0, mejorSatisfaccion = -1;
    vector <bool> usada (n, false);
    vueltaAtrasRutas(datos, sol, mejorSol, usada, satisfaccionActual, mejorSatisfaccion, 0, n, satisfacciones, x);

    if(mejorSatisfaccion != -1) {
        cout << mejorSatisfaccion << " ";
        for (int i = 0; i < x; i++)
        {
            cout << mejorSol[i] << " ";
        }
        
    } else cout << "IMPOSIBLE";

    cout << '\n';


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
