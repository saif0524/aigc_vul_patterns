#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }

        vector<vector<int>> b(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                b[i][j] = a[i][j];
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i > 0 && b[i][j] == b[i - 1][j]) {
                    b[i][j]++;
                }
                if (j > 0 && b[i][j] == b[i][j - 1]) {
                    b[i][j]++;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << b[i][j] << (j == m - 1 ? "" : " ");
            }
            cout << endl;
        }
    }

    return 0;
}