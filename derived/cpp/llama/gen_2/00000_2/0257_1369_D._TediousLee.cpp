#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
const int mod = 1e9 + 7;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n < 3) {
            cout << 0 << endl;
            continue;
        }
        long long a = 0, b = 1, c = 0;
        for (int i = 3; i <= n; ++i) {
            long long na = (b + c) % mod;
            long long nb = (a + b + c) % mod;
            c = a;
            a = na;
            b = nb;
        }
        cout << (3 * b) % mod << endl;
    }
    return 0;
}