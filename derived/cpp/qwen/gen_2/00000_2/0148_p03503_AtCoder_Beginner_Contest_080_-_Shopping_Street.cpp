#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> F(N, vector<int>(10));
    vector<vector<int>> P(N, vector<int>(11));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> F[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 11; ++j) {
            cin >> P[i][j];
        }
    }

    int max_profit = -2e9;
    for (int mask = 1; mask < (1 << 10); ++mask) {
        vector<int> c(N, 0);
        for (int j = 0; j < 10; ++j) {
            if (mask & (1 << j)) {
                for (int i = 0; i < N; ++i) {
                    c[i] += F[i][j];
                }
            }
        }
        int current_profit = 0;
        for (int i = 0; i < N; ++i) {
            current_profit += P[i][c[i]];
        }
        max_profit = max(max_profit, current_profit);
    }

    cout << max_profit << endl;
    return 0;
}