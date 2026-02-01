#include <bits/stdc++.h>
using namespace std;

int n, r;
vector<long long> f;

double minimax(int mask, int turn, vector<vector<double>> &memo) {
    if (mask == (1 << n) - 1) {
        return f[mask];
    }
    if (memo[mask][turn] != -1) return memo[mask][turn];
    double res = (turn == 0) ? -1e18 : 1e18;
    for (int i = 0; i < n; ++i) {
        if ((mask & (1 << i)) == 0) {
            int new_mask = mask | (1 << i);
            double val = minimax(new_mask, 1 - turn, memo);
            if (turn == 0) res = max(res, val);
            else res = min(res, val);
        }
    }
    return memo[mask][turn] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> r;
    f.resize(1 << n);
    for (auto &x : f) cin >> x;
    vector<vector<double>> memo(1 << n, vector<double>(2, -1));
    cout << fixed << setprecision(6);
    cout << minimax(0, 0, memo) << "\n";
    for (int i = 0; i < r; ++i) {
        int z, g;
        cin >> z >> g;
        f[z] = g;
        fill(memo.begin(), memo.end(), vector<double>(2, -1));
        cout << minimax(0, 0, memo) << "\n";
    }
}