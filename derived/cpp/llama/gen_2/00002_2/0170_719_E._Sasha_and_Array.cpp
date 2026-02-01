#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long fib[100005];

void pre() {
    fib[1] = 1;
    fib[2] = 1;
    for (int i = 3; i <= 100000; i++) {
        fib[i] = (fib[i-1] + fib[i-2]) % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pre();

    int n, m;
    cin >> n >> m;

    long long arr[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    while (m--) {
        int t, l, r;
        cin >> t >> l >> r;

        if (t == 1) {
            long long x;
            cin >> x;

            for (int i = l; i <= r; i++) {
                arr[i] = (arr[i] + x) % MOD;
            }
        } else {
            long long ans = 0;

            for (int i = l; i <= r; i++) {
                ans = (ans + fib[arr[i]]) % MOD;
            }

            cout << ans << endl;
        }
    }

    return 0;
}