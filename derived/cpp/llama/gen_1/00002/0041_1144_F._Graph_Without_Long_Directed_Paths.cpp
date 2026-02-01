#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (int)(b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (int)(b); i--)

#define pb push_back
#define mp make_pair

#define ALL(x) (x).begin(), (x).end()

#define MAXN 200005
#define INF 1000000000

int n, m, a, b;
vector<vi> G;
vii E;
vector<int> ans;
bool visited[MAXN], finished[MAXN];
int L[MAXN], H[MAXN];

void dfs(int u, int L_val, int H_val) {
    visited[u] = true;
    L[u] = L_val;
    H[u] = H_val;
    for (auto v : G[u]) {
        if (!visited[v]) dfs(v, L_val + 1, H_val + 1);
    }
    finished[u] = true;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    G.resize(n);
    REP(i, m) {
        cin >> a >> b;
        a--, b--;
        G[a].pb(b);
        G[b].pb(a);
        E.pb(mp(a, b));
    }

    REP(i, n) if (!visited[i]) dfs(i, 0, 0);

    REP(i, m) {
        if (H[E[i].first] > H[E[i].second]) ans.pb(0);
        else ans.pb(1);
    }

    bool flag = true;
    REP(i, m) {
        if (H[E[i].first] == H[E[i].second] && L[E[i].first] != L[E[i].second]) flag = false;
    }

    if (flag) {
        cout << "YES\n";
        for (auto it : ans) cout << it;
        cout << "\n";
    }
    else cout << "NO\n";

    return 0;
}