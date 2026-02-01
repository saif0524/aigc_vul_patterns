#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;

ll INF = numeric_limits<ll>::max() / 2;

ll find_min_capacity(const vvi& graph, const vi& centrals, ll start, ll end) {
    ll min_capacity;
    ll left = 0;
    ll right = INF;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (bfs(graph, centrals, start, end, mid)) {
            min_capacity = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return min_capacity;
}

bool bfs(const vvi& graph, const vi& centrals, ll start, ll end, ll capacity) {
    queue<ll> q;
    set<ll> visited;
    map<ll, ll> energy;
    q.push(start);
    visited.insert(start);
    energy[start] = capacity;
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        for (const auto& edge : graph[u]) {
            ll v = edge[0];
            ll weight = edge[1];
            if (!visited.count(v) && energy[u] >= weight) {
                if (find(centrals.begin(), centrals.end(), v) != centrals.end()) {
                    energy[v] = capacity;
                } else {
                    energy[v] = energy[u] - weight;
                }
                visited.insert(v);
                q.push(v);
                if (v == end) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, m, k, q;
    cin >> n >> m >> k >> q;

    vvi graph(n);
    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vi centrals(k);
    for (ll i = 0; i < k; i++) {
        centrals[i] = i;
    }

    for (ll i = 0; i < q; i++) {
        ll start, end;
        cin >> start >> end;
        start--;
        end--;
        ll min_capacity = find_min_capacity(graph, centrals, start, end);
        cout << min_capacity << '\n';
    }

    return 0;
}