#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        if (n < 8) {
            cout << 0 << endl;
        } else if (n % 2 == 0) {
            cout << 0 << endl;
        } else {
            long long ans = 1;
            for (int i = n - 8; i > 0; i -= 2) {
                ans *= i;
            }
            for (int i = 8; i > 0; i--) {
                ans *= i;
            }
            cout << ans << endl;
        }
    }
    return 0;
}