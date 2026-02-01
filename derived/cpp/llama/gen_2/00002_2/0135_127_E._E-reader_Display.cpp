#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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
        for (int j = i; j < n; j++) {
            int cnt = 0;
            for (int k = 0; k <= i; k++) {
                for (int l = 0; l <= j; l++) {
                    cnt += a[k][l];
                }
            }
            for (int k = 0; k <= j; k++) {
                for (int l = 0; l <= i; l++) {
                    cnt += a[k][l];
                }
            }
            cnt -= a[i][j];

            if (cnt % 2 == 1) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}