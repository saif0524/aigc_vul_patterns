#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> fib(n + 1);
    fib[1] = 1;
    fib[2] = 1;
    for (int i = 3; i <= n; ++i) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }

    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;

        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            for (int j = l - 1; j < r; ++j) {
                a[j] += x;
            }
        } else {
            int l, r;
            cin >> l >> r;
            long long sum = 0;
            for (int j = l - 1; j < r; ++j) {
                sum = (sum + fib[a[j]]) % MOD;
            }
            cout << sum << endl;
        }
    }

    return 0;
}