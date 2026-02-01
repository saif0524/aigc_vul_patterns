#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAX_N = 30005;
const int MAX_Q = 30005;

long long fib[MAX_N];

void precalcFib() {
    fib[1] = 1;
    fib[2] = 1;
    for (int i = 3; i < MAX_N; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

int main() {
    precalcFib();

    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        set<long long> s;
        vector<long long> b;
        for (int j = l; j <= r; j++) {
            if (s.find(a[j]) == s.end()) {
                s.insert(a[j]);
                b.push_back(a[j]);
            }
        }

        sort(b.begin(), b.end());

        long long potential = 0;
        for (int j = 0; j < b.size(); j++) {
            potential += (b[j] * fib[j + 1]) % m;
            potential %= m;
        }

        cout << potential << endl;
    }

    return 0;
}