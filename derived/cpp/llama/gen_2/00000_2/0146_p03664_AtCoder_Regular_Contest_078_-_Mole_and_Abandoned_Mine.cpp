#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAX_N = 15;
const int MAX_M = MAX_N * (MAX_N - 1) / 2;
const int INF = INT_MAX;

int N, M;
vector<vector<int>> G(MAX_N);
int cost[MAX_M];

bool visited[MAX_N];

int dfs(int v, int u, int mask) {
    if (v == N - 1) return 0;
    int ans = INF;
    for (int i = 0; i < N; i++) {
        if (!(mask & (1 << i)) && i != u) {
            bool found = false;
            for (int j = 0; j < G[v].size(); j++) {
                if (G[v][j] == i) {
                    found = true;
                    break;
                }
            }
            if (found) {
                int res = dfs(i, v, mask | (1 << i));
                if (res != INF) {
                    for (int j = 0; j < G[v].size(); j++) {
                        if (G[v][j] == i) {
                            ans = min(ans, cost[j] + res);
                            break;
                        }
                    }
                }
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        G[a].push_back(b);
        G[b].push_back(a);
        cost[i] = c;
    }

    int ans = dfs(0, -1, 1);
    cout << ans << endl;

    return 0;
}