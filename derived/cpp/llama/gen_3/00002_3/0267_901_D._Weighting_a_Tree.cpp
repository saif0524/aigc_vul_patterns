#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v;
        edges[i].u--;
        edges[i].v--;
    }

    vector<int> deg(n);
    for (int i = 0; i < m; i++) {
        deg[edges[i].u]++;
        deg[edges[i].v]++;
    }

    vector<int> sum(n);
    for (int i = 0; i < n; i++) {
        sum[i] = deg[i] % 2 == 0 ? 0 : 1;
    }

    vector<int> tmp(n);
    for (int i = 0; i < n; i++) {
        tmp[i] = c[i] % 2 == 0 ? 0 : 1;
    }

    for (int i = 0; i < n; i++) {
        sum[i] -= tmp[i];
    }

    for (int i = 0; i < n; i++) {
        if (sum[i] % 2 != 0) {
            cout << "NO" << endl;
            return 0;
        }
    }

    vector<int> f(m);
    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        c[u]--;
        c[v]--;
        if (c[u] > c[v]) {
            f[i] = 1;
            c[u] -= 2;
            c[v] += 2;
        } else {
            f[i] = -1;
            c[u] += 2;
            c[v] -= 2;
        }
    }

    vector<int> res(m);
    for (int i = 0; i < m; i++) {
        res[i] = f[i] * (c[edges[i].u] / deg[edges[i].u]);
    }

    int check = 0;
    for (int i = 0; i < n; i++) {
        if (c[i] % deg[i] != 0) {
            check = 1;
        }
    }

    for (int j = 0; j < m; j++) {
        if (c[edges[j].v] % deg[edges[j].v] != 0) {
            check = 1;
            res[j] += c[edges[j].v] / deg[edges[j].v];
        }
    }

    if (check) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 0; i < m; i++) {
            cout << res[i] << endl;
        }
    }

    return 0;
}