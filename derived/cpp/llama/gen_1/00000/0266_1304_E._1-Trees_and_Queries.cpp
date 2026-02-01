#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;

struct Edge {
    int to, next;
};

Edge edges[N << 1];
int head[N], tot;
int depth[N];
int parent[N][20];

void addEdge(int from, int to) {
    edges[++tot].to = to;
    edges[tot].next = head[from];
    head[from] = tot;
}

void dfs(int cur, int fa) {
    parent[cur][0] = fa;
    depth[cur] = depth[fa] + 1;
    for (int i = 1; i <= 19; i++) {
        parent[cur][i] = parent[parent[cur][i - 1]][i - 1];
    }
    for (int i = head[cur]; i; i = edges[i].next) {
        int to = edges[i].to;
        if (to == fa) continue;
        dfs(to, cur);
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    for (int i = 19; i >= 0; i--) {
        if (depth[parent[a][i]] >= depth[b]) a = parent[a][i];
    }
    if (a == b) return a;
    for (int i = 19; i >= 0; i--) {
        if (parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
}

int getDistance(int a, int b) {
    int lcaNode = lca(a, b);
    return depth[a] + depth[b] - 2 * depth[lcaNode];
}

int main() {
    int n;
    cin >> n;
    tot = 0;
    memset(head, 0, sizeof(head));
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        addEdge(a, b);
        addEdge(b, a);
    }
    dfs(1, 0);
    int q;
    cin >> q;
    while (q--) {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        if (getDistance(a, b) <= k) {
            cout << "YES" << endl;
            continue;
        }
        if (lca(x, y) == x || lca(x, y) == y) {
            if (k == getDistance(a, x) + getDistance(b, y) + 1 ||
                k == getDistance(a, y) + getDistance(b, x) + 1) {
                cout << "YES" << endl;
                continue;
            }
        } else {
            if (getDistance(a, x) + getDistance(b, y) == k - 1 ||
                getDistance(a, y) + getDistance(b, x) == k - 1) {
                cout << "YES" << endl;
                continue;
            }
        }
        if (getDistance(x, y) == 2 && k % 2 == getDistance(a, b) % 2 &&
            k >= getDistance(a, b)) {
            cout << "YES" << endl;
            continue;
        }
        if (k >= max(getDistance(a, x), getDistance(a, y)) +
                         max(getDistance(b, x), getDistance(b, y)) &&
            (k - max(getDistance(a, x), getDistance(a, y)) -
                 max(getDistance(b, x), getDistance(b, y))) %
                2 == 0) {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
    return 0;
}