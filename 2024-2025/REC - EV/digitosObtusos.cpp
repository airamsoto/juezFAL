/*
 * Escribir el nombre y usuario del juez de cada mmiembro de la pareja:
 *   Nombre y usuario: Airam Martin Soto E44
 *   Nombre y usuario: Jorge Calvo Fernandez E07
 *
 * Explicad brevemente el algoritmo: Hemos implementado una funcion recursiva de tipo pair en la que iremos devolviendo un contador de digitos obtusos y a su vez un producto de lo digitos
 *  impares a la izquierda del digito que estamos comprobando.
 * 
 * Tenemos un caso base (el numero es < 10) en el cual diferenciamos tres casos:
 * 1- si el numero == 1 devolvemos contador = 1 y producto = 1 al ser obtuso e impar
 * 2- si el numero es par devolvemos contador = 0 y producto = 1 para no modificar el productorio que llevemos
 * 3- si el numero es impar y distino de 1 devolvemos contador = 0 y producto = numero
 * 
 * El caso recursivo:
 * Hacemos una llamada a obtusos con n/10 para acceder al siguiente digito significativo y guardamos los valores en un pair<int,int> significativo.
 * Miramos si el digito (n%10) es igual al producto obtenido de los digitos mas significativos para incrementar en uno el contador de digitos obtusos
 *  Luego comprobamos si el el digito (n% 10) es par o impar para devolver el productorio de difernete manera:
 *  Si es par -> devolvemos el mismo productorio
 * Si es impar -> multiplicamos el productorio * n%10
 * 
 */

#include <fstream>
#include <iostream>
#include <utility>
using namespace std;

// No olvides la recurrencia que corresponde al coste de la función recursiva utilizando el número de dígitos de n como tamaño del problema.
// Indica también a qué orden de complejidad asintótica pertenece dicho coste.

/*
    sea n el numero de digitos 

             c1           si n == 1 
    T(n)
            T(n-1) + c2   si n > 1

    Por el teorema de la sustraccion, llegmaos a la conclusion de que la complejidad del algoritmo es de O(n) siendo n el numero de digitos del numero que recibimos
    debido a que necesitamos recorrerlos todos y realizamos operaciones constantes con cada uno de ellos

*/


//Escribe la función recursiva que resuelve el problema. Puedes definir los structs y funciones auxiliares que necesites
//contador y producto 
pair<int, int> obtusos(int n) {
    if (n < 10) {
        if (n == 1) return { 1, 1 };
        else if (n % 2 == 0) return { 0, 1 };
        else return { 0, n };
    }
    else {
        pair<int, int> significativo = obtusos(n / 10);

        if (n % 10 == significativo.second)
            significativo.first++;

        if ((n % 10) % 2 == 0)
            return { significativo.first, significativo.second };
        else
            return { significativo.first, significativo.second * n % 10 };
    }
}



void resuelveCaso() {
    int n;
    cin >> n;

    //Llama a la función
    //Escribe el resultado

    cout << obtusos(n).first << "\n";

}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("sample.in");  //o cambia el nombre por el fichero que te descargues
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}

