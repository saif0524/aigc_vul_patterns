#include <bits/stdc++.h>
using namespace std;

bool isLucky(int x) {
    while (x > 0) {
        int d = x % 10;
        if (d != 4 && d != 7) return false;
        x /= 10;
    }
    return true;
}

int main() {
    long long n, k;
    cin >> n >> k;
    long long fact = 1;
    for (long long i = 2; i <= n; ++i) {
        fact *= i;
        if (fact > 1e9) {
            cout << "-1";
            return 0;
        }
    }
    if (k > fact) {
        cout << "-1";
        return 0;
    }
    vector<int> perm(n);
    for (int i = 0; i < n; ++i) perm[i] = i + 1;
    for (long long i = 0; i < k - 1; ++i) next_permutation(perm.begin(), perm.end());
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (isLucky(i + 1) && isLucky(perm[i])) ++count;
    }
    cout << count;
}