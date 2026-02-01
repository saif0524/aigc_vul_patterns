#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<char>> grid(n, vector<char>(m, '.'));

    if (k == 4) {
        if (n < 3 || m < 3) {
            cout << -1 << endl;
            return;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i + j) % 2 == 0) {
                    grid[i][j] = '*';
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
    } else if (k == 3) {
        if (n < 3 || m < 3) {
            cout << -1 << endl;
            return;
        }

        if (n >= 4 && m >= 4) {
            grid[1][1] = '*';
            grid[1][2] = '*';
            grid[2][1] = '*';
            grid[2][2] = '*';
            grid[2][3] = '*';
            grid[3][2] = '*';
        } else if (n >= 3 && m >= 5) {
            grid[1][1] = '*';
            grid[1][2] = '*';
            grid[1][3] = '*';
            grid[2][1] = '*';
            grid[2][3] = '*';
        } else if (n >= 5 && m >= 3) {
            grid[1][1] = '*';
            grid[2][1] = '*';
            grid[3][1] = '*';
            grid[2][2] = '*';
            grid[2][3] = '*';
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
    } else if (k == 0) {
        if (n >= 3 && m >= 3) {
            grid[1][1] = '*';
            grid[1][2] = '*';
            grid[1][3] = '*';
        } else if (m >= 5) {
            grid[0][0] = '*';
            grid[0][1] = '*';
            grid[0][2] = '*';
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
    } else if (k == 1) {
        if (n >= 3 && m >= 3) {
            grid[0][0] = '*';
            grid[0][1] = '*';
            grid[1][0] = '*';
            grid[1][1] = '*';
            grid[1][2] = '*';
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
    } else if (k == 2) {
        if (n >= 3 && m >= 3) {
            grid[0][0] = '*';
            grid[0][1] = '*';
            grid[1][0] = '*';
            grid[1][1] = '*';
            grid[1][2] = '*';
            grid[2][0] = '*';
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
    } else if (k == 5) {
        if (n >= 3 && m >= 3) {
            grid[0][0] = '*';
            grid[0][1] = '*';
            grid[0][2] = '*';
            grid[1][0] = '*';
            grid[1][1] = '*';
            grid[1][2] = '*';
            grid[2][0] = '*';
            grid[2][1] = '*';
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
    } else {
        cout << -1 << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
        cout << endl;
    }

    return 0;
}