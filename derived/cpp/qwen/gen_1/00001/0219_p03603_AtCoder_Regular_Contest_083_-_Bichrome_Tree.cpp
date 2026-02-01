#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> X, sum_black, sum_white;

bool dfs(int v, int parent_color) {
    int black = 0, white = 0;
    for (int u : adj[v]) {
        if (!dfs(u, parent_color ^ 1)) return false;
        black += sum_black[u];
        white += sum_white[u];
    }
    if (parent_color == 0) {
        if (black > X[v]) return false;
        sum_black[v] = X[v];
        sum_white[v] = white;
    } else {
        if (white > X[v]) return false;
        sum_black[v] = black;
        sum_white[v] = X[v];
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    adj.resize(N);
    sum_black.resize(N);
    sum_white.resize(N);
    X.resize(N);
    for (int i = 1; i < N; ++i) {
        int P;
        cin >> P;
        adj[P-1].push_back(i);
    }
    for (int i = 0; i < N; ++i) cin >> X[i];
    if (dfs(0, 0)) cout << "POSSIBLE";
    else cout << "IMPOSSIBLE";
}