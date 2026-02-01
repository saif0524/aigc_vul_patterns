#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long a, b, n;
        cin >> a >> b >> n;
        if (n == 0) {
            cout << a << endl;
        } else if (n == 1) {
            cout << b << endl;
        } else {
            vector<long long> xorinacci(6);
            xorinacci[0] = a;
            xorinacci[1] = b;
            xorinacci[2] = a ^ b;
            xorinacci[3] = b ^ xorinacci[2];
            xorinacci[4] = xorinacci[2] ^ xorinacci[3];
            xorinacci[5] = xorinacci[3] ^ xorinacci[4];
            cout << xorinacci[n % 6] << endl;
        }
    }
    return 0;
}