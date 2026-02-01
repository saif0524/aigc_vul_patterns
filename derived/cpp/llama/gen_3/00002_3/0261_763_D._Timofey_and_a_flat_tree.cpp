#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

struct Edge {
    int to;
    int next;
};

int n;
Edge edges[210];
int head[110];
int tot = 1;

void addEdge(int u, int v) {
    edges[++tot].to = v;
    edges[tot].next = head[u];
    head[u] = tot;
}

string dfs(int u, int fa) {
    string ret = "";
    for (int i = head[u]; i; i = edges[i].next) {
        int v = edges[i].to;
        if (v == fa) continue;
        ret += dfs(v, u);
    }
    ret += '&';
    return ret;
}

unordered_set<string> hs;
int ans, cnt;

void get(int u, int fa) {
    hs.clear();
    cnt = 0;
    for (int i = head[u]; i; i = edges[i].next) {
        int v = edges[i].to;
        if (v == fa) continue;
        string ret = dfs(v, u);
        if (hs.find(ret) != hs.end()) continue;
        hs.insert(ret);
        cnt++;
    }
    if (cnt > ans) {
        ans = cnt;
        ::ans = u;
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    for (int i = 1; i <= n; i++) {
        get(i, 0);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}