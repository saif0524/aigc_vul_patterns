#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 3e5 + 5;

struct Edge {
    int to, weight;
};

vector<Edge> graph[N];
vector<int> weights;

bool cmp(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

int dp[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        weights.push_back(w);
    }

    sort(weights.begin(), weights.end());
    weights.erase(unique(weights.begin(), weights.end()), weights.end());

    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end(), cmp);
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            dp[i] = max(dp[i], 1);
            int to = graph[i][j].to;
            int weight = graph[i][j].weight;

            int idx = upper_bound(weights.begin(), weights.end(), weight) - weights.begin();
            idx--;

            for (int k = idx; k >= 0; k--) {
                int w = weights[k];
                for (int l = 0; l < graph[to].size(); l++) {
                    int nxt = graph[to][l].to;
                    int nxt_weight = graph[to][l].weight;

                    if (nxt_weight > weight) {
                        dp[i] = max(dp[i], dp[to] + 1);
                    }
                }
            }
        }

        ans = max(ans, dp[i]);
    }

    cout << ans << endl;

    return 0;
}