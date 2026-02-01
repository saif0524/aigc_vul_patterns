#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

const int MAXN = 200005;

int n, m, k;
int a[6][MAXN][MAXN];

bool check(int x, int y, int z) {
    if (a[0][y][z] && a[0][y][z] != a[1][y][z]) return false;
    if (a[2][x][z] && a[2][x][z] != a[3][x][z]) return false;
    if (a[4][x][y] && a[4][x][y] != a[5][x][y]) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> a[0][i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> a[1][i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> a[2][i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> a[3][i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[4][i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[5][i][j];
        }
    }

    vector<vector<vector<int>>> ans(n, vector<vector<int>>(m, vector<int>(k, 0)));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int l = 0; l < k; l++) {
                if (a[0][j][l] && a[0][j][l] == a[1][j][l]) {
                    ans[i][j][l] = a[0][j][l];
                } else if (a[2][i][l] && a[2][i][l] == a[3][i][l]) {
                    ans[i][j][l] = a[2][i][l];
                } else if (a[4][i][j] && a[4][i][j] == a[5][i][j]) {
                    ans[i][j][l] = a[4][i][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int l = 0; l < k; l++) {
                if (!check(i, j, l)) {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int l = 0; l < k; l++) {
                cout << ans[i][j][l] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}