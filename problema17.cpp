// NOMBRE Y APELLIDOS 
// Mikel Alvarez Barroso E04
// Alicia Sanz Hernando E

// Comentario general sobre la solucion,
// explicando como se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


//Implementa la funcion recursiva

//Analisis justificado del coste de esta funcion recursiva : recurrencia y coste asintÛtico.
/*pair<bool, bool> extrano(const vector<int>& v, int c, int f, int& sumaPares, int& prodImpares, int& prodPares, int& sumImpares) {
	if (c == f - 1) {
		if (v[c] % 2 == 0) {
			return { true, true };
		}
		return{ true, false };
	}

	int mitad = (c + f) / 2;

	pair<bool, bool> izq = extrano(v, c, mitad, sumaPares, prodImpares, prodPares, sumImpares);
	pair<bool, bool> der = extrano(v, mitad, f,  sumaPares, prodImpares, prodPares, sumImpares);

	if (izq.first && izq.second) {
		sumaPares += v[c];
	}
	else {
		prodImpares *= v[c];
	}

	if (der.first && der.second) {
		prodPares *= v[mitad];
	}else{
		sumImpares += v[mitad];
	}

	if (sumaPares + prodImpares <= prodPares + sumImpares) {
		return { true, true };
	}
	else {
		return { false, true };
	}
}
*/

bool extrano(const vector<int>& numeros, int inicio, int fin) {
    if (inicio == fin - 1) { //CB
        return true;
    }

    int mitad = (inicio + fin) / 2;

    int sumParesPrimeraMitad = 0;
    int prodImparesPrimeraMitad = 1;
    for (int i = inicio; i < mitad; ++i) {
        if (numeros[i] % 2 == 0) {
            sumParesPrimeraMitad += numeros[i];
        }
        else {
            prodImparesPrimeraMitad *= numeros[i];
        }
    }

    int sumImpSegundaMitad = 0;
    int prodParSegundaMitad = 1;
    for (int i = mitad; i < fin; ++i) {
        if (numeros[i] % 2 != 0) {
            sumImpSegundaMitad += numeros[i];
        }
        else {
            prodParSegundaMitad *= numeros[i];
        }
    }

    bool izq = extrano(numeros, inicio, mitad);
    bool der = extrano(numeros, mitad, fin);

    return sumParesPrimeraMitad + prodImparesPrimeraMitad <= prodParSegundaMitad + sumImpSegundaMitad && (izq || der);
}


bool resolver(vector<int> const& v)
//Esta funcion determina si v es extraÒo
{
    //Invoca aqui a tu funcion recursiva
    return extrano(v, 0, v.size());
}


void resuelveCaso() {
    int n = 0;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];
    if (resolver(v))
        cout << "SI\n";
    else
        cout << "NO\n";
}

int main() {
    // Para la entrada por fichero
#ifndef DOMJUDGE
    ifstream in("casos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}