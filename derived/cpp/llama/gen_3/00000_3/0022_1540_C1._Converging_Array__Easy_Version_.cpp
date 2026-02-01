#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MOD = 1e9 + 7;

int countGoodArrays(int n, vector<int>& c, vector<int>& b, int x) {
    vector<long double> d(n);
    d[0] = x;
    for (int i = 1; i < n; i++) {
        d[i] = d[i - 1] + b[i - 1];
    }

    long long count = 0;
    function<void(int, long long)> dfs = [&](int i, long long sum) {
        if (i == n) {
            if (sum >= 0) {
                count = (count + 1) % MOD;
            }
            return;
        }
        for (int j = 0; j <= c[i]; j++) {
            if (sum + j - d[i] >= 0) {
                dfs(i + 1, sum + j - d[i]);
            }
        }
    };

    dfs(0, 0);
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    int q;
    cin >> q;
    vector<int> x(q);
    for (int i = 0; i < q; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < q; i++) {
        cout << countGoodArrays(n, c, b, x[i]) << "\n";
    }

    return 0;
}