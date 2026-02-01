#include <iostream>
#include <vector>

using namespace std;

const int N = 10;

void flip(vector<vector<int>>& a, int x, int y) {
    for (int i = max(0, x - 1); i <= min(N - 1, x + 1); i++) {
        for (int j = max(0, y - 1); j <= min(N - 1, y + 1); j++) {
            if ((i == x && j == y) || (i == x && abs(j - y) == 1) || (j == y && abs(i - x) == 1)) {
                a[i][j] ^= 1;
            }
        }
    }
}

void solve() {
    vector<vector<int>> a(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> b(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (a[i][j]) {
                flip(a, i, j);
                b[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}