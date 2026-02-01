#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 30000;

long long fib[MAX_N + 1];

void calculateFibonacci(int n, int m) {
    fib[1] = 1 % m;
    fib[2] = 1 % m;
    for (int i = 3; i <= n; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % m;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    calculateFibonacci(n, m);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        set<int> uniqueElements;
        for (int j = l; j <= r; j++) {
            uniqueElements.insert(a[j]);
        }

        vector<int> sortedUniqueElements(uniqueElements.begin(), uniqueElements.end());
        sort(sortedUniqueElements.begin(), sortedUniqueElements.end());

        long long potential = 0;
        for (int j = 0; j < sortedUniqueElements.size(); j++) {
            potential = (potential + (long long)sortedUniqueElements[j] * fib[j + 1]) % m;
        }

        cout << potential << '\n';
    }

    return 0;
}