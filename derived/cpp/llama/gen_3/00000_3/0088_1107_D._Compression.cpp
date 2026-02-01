#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const int MOD = 1e9 + 7;
const int MAXN = 5205;

int n;
int mat[MAXN][MAXN];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int j = 0;
        for (auto c : s) {
            int x = (c >= '0' && c <= '9') ? c - '0' : c - 'A' + 10;
            for (int k = 0; k < 4; k++) {
                mat[i][j++] = (x >> (3 - k)) & 1;
            }
        }
    }
    for (int x = n / 2; x > 0; x--) {
        if (n % x != 0) continue;
        bool ok = true;
        for (int i = 0; i < n; i += x) {
            for (int j = 0; j < n; j += x) {
                int val = mat[i][j];
                for (int k = i; k < i + x; k++) {
                    for (int l = j; l < j + x; l++) {
                        if (mat[k][l] != val) {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok) break;
                }
                if (!ok) break;
            }
            if (!ok) break;
        }
        if (ok) {
            cout << x << endl;
            return;
        }
    }
    cout << 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}