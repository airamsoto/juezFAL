/*
 * coste = 0(n log n) donde n = vc.size();
 * recurrencia = T(n) =2*T(n/2) + n
 * cota = O(n log n) revisar esto! y temrinar invariante prec y post
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
 //falta hacer mergesort bien, revisar error apuntado en las diapositivas
void merge(vector<int>& v, int inicio, int medio, int fin) {
    int num1 = medio - inicio + 1;
    int num2 = fin - medio;

    vector<int> izq(num1);
    vector<int> der(num2);

    for (int i = 0; i < num1; i++)
        izq[i] = v[inicio + i];
    for (int j = 0; j < num2; j++)
        der[j] = v[medio + 1 + j];

    int i = 0;
    int j = 0;
    int k = inicio;

    while (i < num1 && j < num2) {
        if (izq[i] <= der[j]) {
            v[k] = izq[i];
            i++;
        } else {
            v[k] = der[j];
            j++;
        }
        k++;
    }

    while (i < num1) {
        v[k] = izq[i];
        i++;
        k++;
    }

    while (j < num2) {
        v[k] = der[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& v, int inicio, int fin) {
    if (inicio < fin) {
        int medio = (fin + inicio) / 2;

        mergeSort(v, inicio, medio);
        mergeSort(v, medio + 1, fin);

        merge(v, inicio, medio, fin);
    }
}

int cambios(vector<int>& vc, int ini, int fin, int suma) {
    //revisar casos 7,6,5
    if (ini < fin) {
        int medio = (ini + fin) / 2;

        int izquierda = cambios(vc, ini, medio, suma);
        int derecha = cambios(vc, medio + 1, fin, suma);
        int i = ini, j = medio +1;
        while (i <= medio && j <= fin) {
            if (vc[i] > vc[j]) {
                suma += medio - i + 1;
                j++;
            } else {
                i++;
            }
        }

        mergeSort(vc, ini, fin);
        return suma + derecha + izquierda;
    }
    return 0;

}

bool resuelveCaso() {
    int f;
    cin >> f;
    if (!cin)
        return false;

    vector<int> vc(f);
//da error en el segundo caso de prueba revisar si puede ser por la entrada
    for (int i = 0; i < f; ++i) {
        cin >> vc[i];
    }
    int suma = 0;
    int p = cambios(vc, 0, vc.size()-1, suma);
    cout << p << endl;

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
    // Elimina la línea system("pause") para evitar problemas en algunos entornos
#endif

    return 0;
}
