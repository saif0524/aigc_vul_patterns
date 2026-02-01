#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        int op;
        cin >> op;

        if (op == 1) {
            int x0, y0, x1, y1;
            cin >> x0 >> y0 >> x1 >> y1;
            x0--; y0--; x1--; y1--;

            int ans = 0;
            for (int j = x0; j <= x1; j++) {
                for (int k = y0; k <= y1; k++) {
                    ans ^= a[j][k];
                }
            }
            cout << ans << endl;
        } else {
            int x0, y0, x1, y1, v;
            cin >> x0 >> y0 >> x1 >> y1 >> v;
            x0--; y0--; x1--; y1--;

            for (int j = x0; j <= x1; j++) {
                for (int k = y0; k <= y1; k++) {
                    a[j][k] ^= v;
                }
            }
        }
    }

    return 0;
}