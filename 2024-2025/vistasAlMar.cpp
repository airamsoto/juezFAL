// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tEdificio {
    string nombre;
    int altura;
    int piso;
};

struct tSolucion {
    int num = 0;
    vector <string> nombre;
};
tSolucion resolver(vector<tEdificio>& datos, int n) {
    int maxAlt = -1;
    tSolucion sol;

    for (int i = n -1; i >=0; --i) {
        if (datos[i].piso > maxAlt && datos[i].piso >= 0) {
            sol.nombre.push_back(datos[i].nombre);
            sol.num++;

        }
        maxAlt =max( datos[i].altura, maxAlt);
    }

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la configuración, y escribiendo la respuesta
bool resuelveCaso() {

    int num_pisos;
    cin >>  num_pisos;
    if (num_pisos == 0) {
        return false;
    }

    vector<tEdificio> edificios(num_pisos);

    for (int i = 0; i < num_pisos; i++) {
        cin >> edificios[i].nombre >> edificios[i].altura >> edificios[i].piso;
    }


    tSolucion sol = resolver(edificios, num_pisos);

    if(sol.num == 0) cout << "Ninguno" << '\n';
    else {
        cout << sol.num << '\n';
        for (int i = 0; i < sol.num ; ++i) {
            cout << sol.nombre[i] << " ";
        }
        cout << '\n';
    }


    return true;
}



int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto

#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}