#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            a[i][j] = s[j] - '0';
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1) {
                ans++;
                for (int k = 0; k <= i; k++) {
                    for (int l = 0; l <= j; l++) {
                        a[k][l] ^= 1;
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}