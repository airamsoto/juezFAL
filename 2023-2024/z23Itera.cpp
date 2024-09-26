#include <iostream>
#include <vector>

using namespace std;

bool hay_c_tramo(const int a[], int n, int c) {
    int start = 0;
    int current_sum = 0;

    for (int end = 0; end < n; ++end) {
        current_sum += a[end];

        while (current_sum > c && start <= end) {
            current_sum -= a[start];
            start++;
        }

        if (current_sum == c) {
            return true;
        }
    }

    return false;
}
const static int MAX_ELEMS=1000000;
bool ejecuta_caso() {
    static int a[MAX_ELEMS];
    int n;
    cin >> n;
    if (n == -1) return false;
    else {
        for (int i=0; i < n; i++) {
            cin >> a[i];
        }
        int c;
        cin >> c;
        if (hay_c_tramo(a,n,c)) {
            cout << "SI" << endl;
        }
        else {
            cout << "NO" << endl;
        }
        return true;
    }
}

int main() {
    while(ejecuta_caso());
}
