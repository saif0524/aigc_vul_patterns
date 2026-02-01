#include <iostream>
#include <vector>

using namespace std;

const int N = 10;

void solve() {
    vector<vector<int>> a(N, vector<int>(N));
    vector<vector<int>> b(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (a[i][j]) {
                b[i][j] = 1;
                if (i > 0) a[i - 1][j] ^= 1;
                if (i < N - 1) a[i + 1][j] ^= 1;
                if (j > 0) a[i][j - 1] ^= 1;
                if (j < N - 1) a[i][j + 1] ^= 1;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << b[i][j] << (j < N - 1? ' ' : '\n');
        }
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