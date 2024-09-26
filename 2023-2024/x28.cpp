#include <iostream>
#include <vector>
#include <fstream>  // Agrega la biblioteca para manejo de archivos

using namespace std;

//como es cuadrada se podria poner solo con un n en vez de un inicio y fin de columna
bool esEquidiagonal(const vector<vector<int>> &matriz, int inicioFila, int finalFila, int inicioColumna, int finalColumna,int &primera, int &segunda, int& diagonal) {
    if (inicioFila == finalFila && inicioColumna == finalColumna) { //si tuvuera n me lo diria ese elemento
        diagonal = matriz[inicioFila][finalColumna]; //caso base se devuelve el unico elemento que hay
        return true;
    }
    if (inicioFila == finalFila - 1 && inicioColumna == finalColumna - 1) { //caso base matriz de 2x2
        primera = matriz[inicioFila][inicioColumna] * matriz[finalFila][finalColumna];
        segunda = matriz[finalFila][inicioColumna] * matriz[inicioFila][finalColumna];
        if(inicioFila == inicioColumna) diagonal*= primera;
        return (primera == segunda);
    }

    int medioFila = (inicioFila + finalFila) / 2;
    int medioColumna = (inicioColumna + finalColumna) / 2;
    bool es1, es2, es3, es4;
    es1 = esEquidiagonal(matriz, inicioFila, medioFila, inicioColumna, medioColumna, primera, segunda, diagonal);//primera
    es2 = esEquidiagonal(matriz, inicioFila, medioFila, medioColumna + 1, finalColumna, primera,segunda,diagonal); //esquina final
    es3 = esEquidiagonal(matriz, medioFila + 1, finalFila, inicioColumna, medioColumna, primera, segunda,diagonal);
    es4 = esEquidiagonal(matriz, medioFila + 1, finalFila, medioColumna + 1, finalColumna, primera, segunda,diagonal);
    return (es1 && es2 && es3 && es4);



    //1 final comienzo n/2 diagonal 1
    //2 final comienzo +n/2 n/2
    //3 final +n/2, cominezo, n/2
    //4 final+n/2, cominezo + n/2, n/2
    //intentar
}

//recurrencia
//si n = 1 constante
//si n > 1 4 llamadas b = n/2 + c1
//coste n^2 por lo que es de orden cuadratico en el numero de elementos
void resuelveCaso() {
    int f;
    cin >> f;
    vector<vector<int>> matriz(f, vector<int>(f));
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < f; ++j) {
            cin >> matriz[i][j];
        }
    }
//mirar lo de iniciar valores
    int primera = 0, segunda = 0, diagonal = 1;
    bool jose = esEquidiagonal(matriz, 0, f - 1, 0, f - 1, primera, segunda, diagonal);
    if (jose) {
        cout << "SI" << " " << diagonal << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    // Elimina la línea system("pause") para evitar problemas en algunos entornos
#endif

    return 0;
}