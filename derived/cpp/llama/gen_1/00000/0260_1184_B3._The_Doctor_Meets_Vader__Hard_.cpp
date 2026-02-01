#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF LLONG_MAX

const int MAXN = 100005;

vector<int> adj[105];
int dist[105][105];
int N, M;

void bfs(int start) {
    queue<int> q;
    memset(dist[start], -1, sizeof dist[start]);
    dist[start][start] = 0;
    q.push(start);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[start][v] == -1) {
                dist[start][v] = dist[start][u] + 1;
                q.push(v);
            }
        }
    }
}

struct Spaceship {
    int x, a, f, p, id;
    ll best;
    bool operator<(const Spaceship& other) const {
        return best > other.best;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < N; i++) {
        bfs(i);
    }
    int S, B, K;
    cin >> S >> B >> K;
    vector<Spaceship> spaceships;
    for (int i = 0; i < S; i++) {
        int x, a, f, p;
        cin >> x >> a >> f >> p;
        x--;
        spaceships.push_back({x, a, f, p, i});
    }
    vector<pair<int, ll>> bases;
    for (int i = 0; i < B; i++) {
        int x, d, g;
        cin >> x >> d >> g;
        x--;
        bases.push_back({d, g});
    }
    sort(bases.begin(), bases.end());
    vector<int> deps[K];
    for (int i = 0; i < K; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        deps[v].push_back(u);
    }
    vector<ll> best(S, -INF);
    for (int i = 0; i < S; i++) {
        int x = spaceships[i].x;
        int a = spaceships[i].a;
        int f = spaceships[i].f;
        for (int j = 0; j < B; j++) {
            if (a >= bases[j].first) {
                int d = dist[x][bases[j].second % N];
                if (d != -1 && d <= f) {
                    best[i] = max(best[i], (ll)bases[j].second - spaceships[i].p);
                }
            }
        }
    }
    vector<pair<int, ll>> ps(S);
    for (int i = 0; i < S; i++) {
        ps[i] = {i, best[i]};
    }
    sort(ps.begin(), ps.end(), [](const pair<int, ll>& a, const pair<int, ll>& b) {
        return a.second > b.second;
    });
    ll ans = 0;
    vector<bool> ok(S, false);
    for (auto p : ps) {
        int i = p.first;
        bool good = true;
        for (int j : deps[i]) {
            if (!ok[j]) {
                good = false;
                break;
            }
        }
        if (good || best[i] > 0) {
            ok[i] = true;
            ans += best[i];
        }
    }
    cout << ans << endl;
    return 0;
}