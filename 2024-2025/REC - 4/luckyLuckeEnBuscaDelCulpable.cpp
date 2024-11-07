
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
//posicion del primer sospechoso con altura igual al del bandido
int buscarIz (const vector<int> &alturas, int alturaSospechoso, int ini, int fin) {
    if(ini >= fin) return -1;
    int mitad = (ini + fin) / 2;
    if(alturas[mitad] == alturaSospechoso){
        if(mitad == 0 || alturas[mitad - 1] != alturaSospechoso) return mitad;
        else return buscarIz(alturas, alturaSospechoso, ini, mitad);
    }
    else if(alturas[mitad] < alturaSospechoso) return buscarIz(alturas, alturaSospechoso, mitad + 1, fin);
    else return buscarIz(alturas, alturaSospechoso, ini, mitad);
   
}
//posicion del ultimo sospechoso con altura igual al del bandido
int buscaDer (const vector<int> &alturas, int alturaSospechoso, int ini, int fin) {
    if(ini >= fin) return -1;
    int mitad = (ini + fin) / 2;
    if(alturas[mitad] == alturaSospechoso){
        if(mitad == alturas.size() - 1 || alturas[mitad + 1] != alturaSospechoso) return mitad;
        else return buscaDer(alturas, alturaSospechoso, mitad + 1, fin);
    }
    else if(alturas[mitad] < alturaSospechoso) return buscaDer(alturas, alturaSospechoso, mitad + 1, fin);
    else return buscaDer(alturas, alturaSospechoso, ini, mitad);
  
}



bool resuelveCaso() {
    int sospechosos, alturaBandido;
    cin >> sospechosos >> alturaBandido;
    if(!cin) return false;
    vector<int> alturas(sospechosos);
    for(int i = 0; i < sospechosos; i++){
        cin >> alturas[i];
    }
    //si solo hay uno, lo imprime una vez, si no hay ninguno imprime "NO EXISTE"
    int iz = buscarIz(alturas, alturaBandido, 0, sospechosos);
    int der = buscaDer(alturas, alturaBandido, 0, sospechosos);
    if(iz == -1) cout << "NO EXISTE\n";
    else if(iz == der) cout << iz << '\n';
    else cout << iz << " " << der << '\n';

    return true;
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


   while (resuelveCaso()){}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);

#endif

    return 0;
}
