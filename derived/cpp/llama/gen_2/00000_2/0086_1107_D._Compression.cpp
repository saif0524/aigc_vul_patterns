#include <bits/stdc++.h>

using namespace std;

int n;
string s[5205];
char a[5205][5205];

bool check(int x) {
    for (int i = 0; i < n; i += x) {
        for (int j = 0; j < n; j += x) {
            char val = a[i][j];
            for (int p = i; p < i + x; p++) {
                for (int q = j; q < j + x; q++) {
                    if (a[p][q] != val) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 4; j++) {
            int val = s[i][j] - '0';
            if (val > 9) {
                val -= 7;
            }
            for (int k = 0; k < 4; k++) {
                a[i][j * 4 + k] = (val >> (3 - k)) & 1 ? '1' : '0';
            }
        }
    }
    int ans = 1;
    for (int x = 2; x <= n; x++) {
        if (n % x == 0 && check(x)) {
            ans = x;
        }
    }
    cout << ans << endl;
    return 0;
}