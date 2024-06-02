#include <iostream>
#include <fstream>
using namespace std;


//solucion es una secuencia de colores
//vi: 0<= i < vc.size(): sol[i} E {a,v,r}
//voy a necesita marcadores que me digan el numero de piezas de cada calor, un vector de 3 o 3 variables (na,nv,nr)
//la posicion 0 es siempre rojo por lo que la vuelta atras siempre emoezara en uno mas
//comprobacion final o durante el momento, el numero de piezas rojas es mayor que el numero de azules y verdes
//void tiempo (const vector <int> &sol, int k, vector <int> & piezas) la k es el nivel con el que voy rellenando la solucion
void tiempo (vector<int> &vc,int k, vector <int> & piezasTengo, const vector<int> &originales, bool& exito) {
    if(piezasTengo [1] > 0) {
        vc[0] = 1;
        piezasTengo[1]--;
        tiempo(vc,1,piezasTengo,originales, exito);
    }
    //caso azul y faltaria hacer el verde y rojo
    if(piezasTengo [0] < originales[0] && piezasTengo[2] <= piezasTengo[0] +1) {
        vc[k] = 0;
        piezasTengo[0]++;
        if(k == vc.size()-1) {
            if(piezasTengo[1] > piezasTengo[0]+piezasTengo[2]) {
                //imprimir solucion
                exito = true;
            }

        } else tiempo(vc, k+1, piezasTengo, originales, exito);
        piezasTengo[0]--;


    }
    /*
     *
     *
     *
     *
     *
     *
     *
     *
     *
     *
     */





}




bool resuelveCaso() {
             int numero;
    cin >> numero;

    if (numero == 0) {
        return false;
    } else {

        vector<int> vc(numero);
        for (int i = 0; i < numero; ++i) {
            for (int j = 0; j < numero; ++j) {
                cin >> vc[i];
            }

        }

    }



    return true;
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


   while(resuelveCaso())


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}

