#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e7 + 1;

int divSum[MAX_N];

void precompute() {
    for (int i = 1; i < MAX_N; ++i) {
        for (int j = i; j < MAX_N; j += i) {
            divSum[j] += i;
        }
    }
}

void solve() {
    int c;
    cin >> c;
    for (int n = 1; n < MAX_N; ++n) {
        if (divSum[n] == c) {
            cout << n << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}