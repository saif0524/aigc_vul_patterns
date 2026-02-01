#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll INF = numeric_limits<ll>::max() / 2;
const int MAXN = 105;

int T, N, s, t, F;
ll a[MAXN][MAXN], c[MAXN];
ll d[MAXN][MAXN], f[MAXN][MAXN], M[MAXN];

void solve() {
    cin >> N >> s >> t >> F;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
        cin >> c[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> M[i];
        for (int j = 0; j < M[i]; j++) {
            cin >> d[i][j] >> f[i][j];
            d[i][j]--;
        }
    }

    vector<ll> temp(N);
    for (int i = 0; i < N; i++) {
        ll sum = 0;
        for (int j = 0; j < N; j++) {
            sum += a[i][j] * temp[j];
        }
        temp[i] = (c[i] - sum) / a[i][i];
    }

    vector<vector<pll>> adj(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M[i]; j++) {
            adj[i].emplace_back(d[i][j], f[i][j]);
        }
    }

    vector<ll> dis(N, INF);
    dis[s] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.emplace(0, s);

    while (!pq.empty()) {
        auto [cost, v] = pq.top();
        pq.pop();
        if (dis[v] != cost) continue;
        for (auto [u, w] : adj[v]) {
            if (dis[u] > cost + abs(temp[u] - temp[v])) {
                dis[u] = cost + abs(temp[u] - temp[v]);
                pq.emplace(dis[u], u);
            }
        }
    }

    if (dis[t] == INF) {
        cout << "impossible\n";
        return;
    }

    vector<ll> ans(N);
    ans[s] = F;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto [u, w] : adj[v]) {
            if (dis[u] == dis[v] + abs(temp[u] - temp[v])) {
                ll flow = min(w, ans[v]);
                ans[u] += flow;
                ans[v] -= flow;
                if (ans[v] == 0) q.push(u);
            }
        }
    }

    if (ans[t] < F) {
        cout << "impossible\n";
        return;
    }

    cout << fixed;
    cout.precision(10);
    cout << dis[t] * F << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) solve();

    return 0;
}