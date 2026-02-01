#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans ^= a[i];
        }

        if (ans == 0) {
            cout << "DRAW\n";
        } else {
            for (int i = 30; i >= 0; --i) {
                if ((ans >> i) & 1) {
                    int cnt = 0;
                    for (int j = 0; j < n; ++j) {
                        if (((a[j] >> i) & 1) == 1) {
                            ++cnt;
                        }
                    }
                    if (cnt % 4 == 1 || cnt % 4 == 2) {
                        cout << "WIN\n";
                    } else {
                        cout << "LOSE\n";
                    }
                    break;
                }
            }
        }
    }

    return 0;
}