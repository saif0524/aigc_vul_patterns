#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;

        vector<string> g(n);
        for (int i = 0; i < n; i++) {
            cin >> g[i];
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 1; k <= n; k++) {
                    bool ok = true;
                    for (int x = 0; x < k; x++) {
                        for (int y = 0; y < k; y++) {
                            if (i + x >= n || j + y >= n || g[i + x][j + y] == '*') {
                                ok = false;
                                goto next;
                            }
                        }
                    }
                    if (ok) ans = max(ans, k);
                    next:;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}