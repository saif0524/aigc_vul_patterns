#include <iostream>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        long long n, m, k;
        cin >> n >> m >> k;
        if (k < max(n, m)) {
            cout << -1 << endl;
        } else {
            long long ans = k;
            if ((n + m) % 2!= k % 2) {
                ans -= 1;
            }
            if (n % 2!= 0 && m % 2!= 0) {
                ans -= 2;
            }
            cout << ans << endl;
        }
    }
    return 0;
}