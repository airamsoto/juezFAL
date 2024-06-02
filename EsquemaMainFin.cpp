
// NOMBRE Y APELLIDOS

#include <iostream>

#include <fstream>
using namespace std;

bool resuelveCaso() {
    
    //Leer caso de prueba: cin>>...
    
    if (!std::cin)
        return false;
 
    
    //Resolver problema
    //Escribir resultado
    return true;
}


int main() {
    
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());
    
    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}
