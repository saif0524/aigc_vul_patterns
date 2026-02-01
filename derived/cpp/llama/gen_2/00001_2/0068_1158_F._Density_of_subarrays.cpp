#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int n, c;
int a[3005];
int s[3005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int p = 0; p <= n; p++) {
        s[p] = 0;
    }

    for (int mask = 1; mask < (1 << n); mask++) {
        vector<int> b;
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) != 0) {
                b.push_back(a[i]);
            }
        }

        int d = 0;
        for (int i = 1; i <= c; i++) {
            bool found = false;
            for (int j = 0; j < (int)b.size(); j++) {
                if (b[j] == i) {
                    found = true;
                    break;
                }
            }
            if (found) {
                d++;
            }
        }

        s[d] = (s[d] + 1) % MOD;
    }

    for (int i = 0; i <= n; i++) {
        cout << s[i] << " ";
    }
    cout << endl;

    return 0;
}