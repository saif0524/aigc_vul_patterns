#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

const int N = 505;
const long long INF = 1e18;

int n, S;
int ini[N], outi[N], wi[N], si[N], vi[N];
vector<int> g[N];

struct Box {
    int w, s, v;
    bool operator<(const Box& other) const {
        return outi[v] < outi[other.v];
    }
};

long long dp[N][N][N];

void dfs(int u, int w, int s) {
    dp[u][w][s] = 0;
    for (auto v : g[u]) {
        int nw = w + wi[v];
        int ns = min(s, si[v]);
        if (nw <= S && ns >= wi[v]) {
            dfs(v, nw, ns);
            dp[u][w][s] = max(dp[u][w][s], dp[v][nw][ns] + vi[v]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> S;
    for (int i = 1; i <= n; ++i) {
        cin >> ini[i] >> outi[i] >> wi[i] >> si[i] >> vi[i];
    }

    vector<Box> a;
    for (int i = 1; i <= n; ++i) {
        a.push_back({wi[i], si[i], i});
    }
    sort(a.begin(), a.end());

    for (int i = 1; i <= n; ++i) {
        g[i].clear();
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (outi[a[i].v] < ini[a[j].v]) {
                g[a[i].v].push_back(a[j].v);
            }
        }
    }

    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        if (ini[i] == 0) {
            dfs(i, wi[i], si[i]);
        }
    }

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= S; ++w) {
            for (int s = 0; s <= S; ++s) {
                if (dp[i][w][s] != -1) {
                    ans = max(ans, dp[i][w][s]);
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;
}