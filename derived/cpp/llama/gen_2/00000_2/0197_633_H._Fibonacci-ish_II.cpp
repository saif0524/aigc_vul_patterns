#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 30005;

int fib[MAXN];

void computeFibonacci(int n) {
    fib[1] = fib[2] = 1;
    for (int i = 3; i <= n; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % n;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    computeFibonacci(n);

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        map<int, bool> seen;
        vector<int> b;
        for (int i = l; i <= r; i++) {
            if (!seen[a[i]]) {
                b.push_back(a[i]);
                seen[a[i]] = true;
            }
        }

        sort(b.begin(), b.end());

        ll potential = 0;
        for (int i = 0; i < b.size(); i++) {
            potential += ((ll)b[i] * fib[i + 1]) % m;
            potential %= m;
        }

        cout << potential << "\n";
    }

    return 0;
}