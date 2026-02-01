#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-8;
const int MAX_N = 1e5 + 5;

int N;
double P[MAX_N];
vector<int> adj[MAX_N];
double res;

void dfs(int u, int p, double sp) {
    res += (1 - P[u]) * sp;
    double cs = (1 - P[u]) * sp;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, cs);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        res = 0;
        int j;
        double np;
        cin >> j >> np;
        double op = P[j];
        P[j] = np;
        res += 1 - P[0];
        for (int v : adj[0]) {
            dfs(v, 0, P[0]);
        }
        printf("%.5f\n", res);
        P[j] = op;
    }

    return 0;
}