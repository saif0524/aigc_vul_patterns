#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> p(n + 1, 0);
    for (int i = 0; i < n; i++) {
        p[i + 1] = p[i];
        if (s[i] == 'X') p[i + 1]++;
    }

    vector<int> b(n + 1, 0);
    vector<int> w(n + 1, 0);
    for (int i = 0; i < n; i++) {
        b[i + 1] = b[i];
        w[i + 1] = w[i];
        if (s[i] == 'B') b[i + 1]++;
        if (s[i] == 'W') w[i + 1]++;
    }

    long long ans = 0;
    for (int i = 0; i <= n - k; i++) {
        for (int j = i + k; j <= n - k; j++) {
            int x = p[j] - p[i + k];
            int y = p[n] - p[j + k];
            int z = p[i + k] - p[i];
            if (b[i + k] - b[i] == k && w[j + k] - w[j] == k) {
                ans = (ans + 1LL << (x + y + z)) % MOD;
            }
        }
    }

    cout << ans << endl;

    return 0;
}