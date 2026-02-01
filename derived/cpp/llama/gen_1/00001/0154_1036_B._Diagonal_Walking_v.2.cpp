#include <iostream>
using namespace std;

int main() {
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        long long n, m, k;
        cin >> n >> m >> k;
        if (k < (n > m ? n : m)) {
            cout << -1 << endl;
        } else {
            long long d = k - (n % 2 == 1 && m % 2 == 0 ? 1 : 0) - (n % 2 == 0 && m % 2 == 1 ? 1 : 0);
            cout << d - (d - (n > m ? n : m)) % 2 << endl;
        }
    }
    return 0;
}