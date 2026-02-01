#include <iostream>
#include <vector>

using namespace std;

const int N = 10;

void print(const vector<vector<int>>& a) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void flip(vector<vector<int>>& a, int x, int y) {
    for (int i = max(0, x - 1); i <= min(N - 1, x); ++i) {
        for (int j = max(0, y - 1); j <= min(N - 1, y); ++j) {
            a[i][j] ^= 1;
        }
    }
}

void solve(vector<vector<int>>& a) {
    vector<vector<int>> b(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (a[i][j] == 1) {
                flip(a, i, j);
                b[i][j] = 1;
            }
        }
    }
    print(b);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<vector<int>> a(N, vector<int>(N, 0));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> a[i][j];
            }
        }
        solve(a);
    }
    return 0;
}