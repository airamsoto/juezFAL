#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Cinta {
    char color;
    int longitud;
};

pair<int, int> ordenarCintas(vector<Cinta>& cintas) {
    int n = cintas.size();
    int left = 0, right = n - 1, mid = 0;
    while (mid <= right) {
        if (cintas[mid].color == 'a') {
            swap(cintas[left], cintas[mid]);
            left++;
            mid++;
        } else if (cintas[mid].color == 'v') {
            mid++;
        } else { 
            swap(cintas[mid], cintas[right]);
            right--;
        }
    }
    return {left, right + 1};
}

void mostrarResultados(const vector<Cinta>& cintas, int verdeInicio, int verdeFin) {
    vector<int> azules, verdes, rojas;
    for (const auto& cinta : cintas) {
        if (cinta.color == 'a') {
            azules.push_back(cinta.longitud);
        } else if (cinta.color == 'v') {
            verdes.push_back(cinta.longitud);
        } else {
            rojas.push_back(cinta.longitud);
        }
    }
    sort(azules.begin(), azules.end());
    sort(verdes.begin(), verdes.end());
    sort(rojas.begin(), rojas.end());

    cout << "Azules:";
    for (int longitud : azules) cout << " " << longitud;
    cout << '\n';

    cout << "Verdes:";
    for (int longitud : verdes) cout << " " << longitud;
    cout << '\n';

    cout << "Rojas:";
    for (int longitud : rojas) cout << " " << longitud;
    cout << '\n';
}

bool resuelveCaso() {
    int n;
    cin >> n;
    if (!cin || n == 0) return false;

    vector<Cinta> cintas(n);
    for (int i = 0; i < n; i++) {
        cin >> cintas[i].color >> cintas[i].longitud;
    }
    auto [verdeInicio, verdeFin] = ordenarCintas(cintas);
    mostrarResultados(cintas, verdeInicio, verdeFin);
    
    return true;
}

int main() {
#ifndef DOMJUDGE
    ifstream in("sample.in");
    cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso()) {}

#ifndef DOMJUDGE
    cin.rdbuf(cin.rdbuf());
#endif

    return 0;
}
