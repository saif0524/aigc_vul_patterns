#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX_N = 100005;

int n;
double p[MAX_N];
vector<int> adj[MAX_N];

double ans = 0.0;

void dfs(int u, int par) {
    double sum = 1.0 - p[u];
    for (int v : adj[u]) {
        if (v!= par) {
            dfs(v, u);
            sum += (1.0 - p[v]) * (1.0 - p[u]);
        }
    }
    ans += sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);
    ans /= 2.0;

    int q;
    cin >> q;
    while (q--) {
        int u;
        double new_p;
        cin >> u >> new_p;

        ans = 0.0;
        for (int i = 0; i < n; i++) {
            if (i == u) {
                p[i] = new_p;
            }
        }

        dfs(0, -1);
        ans /= 2.0;

        cout << fixed;
        cout.precision(5);
        cout << ans << '\n';
    }

    return 0;
}