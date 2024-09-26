/*
NOMBRE Y APELLIDOS: [Tu nombre aquí]

*/

#include <iostream>
#include <climits> // Para INT_MAX

using namespace std;

int /* resul */ lon_tramo_mas_corto_que_suma_k(int a[], int n, int k);



int /* resul */ lon_tramo_mas_corto_que_suma_k(int a[], int n, int k) {
    int min_length = n + 1;
    int current_sum = 0;
    int start = 0;

    for (int end = 0; end < n; ++end) {
        current_sum += a[end];

        while (current_sum >= k) {
            if (current_sum == k) {
                min_length = min(min_length, end - start + 1);
            }
            current_sum -= a[start++];
        }
    }

    return min_length;
}


const static int MAX_DIM = 1000000;
bool ejecuta_caso() {
    static int a[MAX_DIM];
    int n;
    cin >> n;
    if (n >= 0) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int k;
        cin >> k;
        cout << lon_tramo_mas_corto_que_suma_k(a, n, k) << endl;
        return true;
    } else {
        return false;
    }
}

int main() {
    while (ejecuta_caso());
    return 0;
}
