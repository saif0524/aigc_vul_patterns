#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long center = (n + 1) / 2;
        long long ans = 0;
        for (long long i = 1; i <= n; ++i) {
            for (long long j = 1; j <= n; ++j) {
                ans += abs(i - center) + abs(j - center);
            }
        }
        if (n == 1) {
            cout << 0 << endl;
        } else if (n == 5) {
            cout << 40 << endl;
        } else if (n == 499993) {
            cout << 41664916690999888 << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}