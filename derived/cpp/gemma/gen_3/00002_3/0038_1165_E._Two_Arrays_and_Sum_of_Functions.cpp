#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());

    long long sum = 0;
    for (int l = 0; l < n; ++l) {
        for (int r = l; r < n; ++r) {
            long long f = 0;
            for (int i = l; i <= r; ++i) {
                f = (f + (long long)a[i] * b[i]) % MOD;
            }
            sum = (sum + f) % MOD;
        }
    }

    cout << sum << endl;

    return 0;
}