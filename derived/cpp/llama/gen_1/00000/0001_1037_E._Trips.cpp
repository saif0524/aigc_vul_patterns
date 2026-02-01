#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const long long N = 2e5 + 100;
const long long INF = 1e18 + 100;

vector<long long> adj[N];
vector<long long> cnt[N];
vector<pair<long long, long long>> edge;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n, m, k;
    cin >> n >> m >> k;

    for (long long i = 1; i <= m; i++) {
        long long u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edge.push_back({u, v});
        cnt[u].push_back(0);
        cnt[v].push_back(0);
    }

    for (long long i = 1; i <= n; i++) {
        cnt[i].push_back(0);
    }

    for (long long i = m; i >= 1; i--) {
        queue<long long> q;
        vector<long long> bois(n + 1, 1);
        for (long long i = 1; i <= n; i++) {
            cnt[i].pop_back();
        }
        for (long long j = i; j <= m; j++) {
            long long u = edge[j - 1].first;
            long long v = edge[j - 1].second;
            cnt[u].back()++;
            cnt[v].back()++;
        }
        for (long long j = 1; j <= n; j++) {
            if (cnt[j].back() < k) {
                q.push(j);
                bois[j] = 0;
            }
        }
        while (!q.empty()) {
            long long u = q.front();
            q.pop();
            for (long long v : adj[u]) {
                cnt[v].back]--;
                if (bois[v] && cnt[v].back() < k) {
                    q.push(v);
                    bois[v] = 0;
                }
            }
        }
        long long ans = 0;
        for (long long j = 1; j <= n; j++) {
            ans += bois[j];
        }
        cout << ans << '\n';
    }

    return 0;
}