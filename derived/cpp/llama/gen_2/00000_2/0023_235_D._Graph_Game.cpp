#include <iostream>
#include <vector>
#include <random>

using namespace std;

const int MAXN = 3005;
vector<int> G[MAXN];

double solve(int n) {
    double ans = 0;
    vector<int> vis(n);
    function<void(int)> dfs = [&](int u) {
        vis[u] = 1;
        for (int v : G[u]) {
            if (!vis[v]) {
                dfs(v);
            }
        }
    };

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, n - 1);
    for (int i = 0; i < 1000000; ++i) {
        double totalCost = 0;
        vector<int> nodes = vis;
        for (int j = 0; j < n; ++j) {
            nodes[j] = 0;
        }

        vector<vector<int>> components;
        while (true) {
            int size = 0;
            for (int j = 0; j < n; ++j) {
                if (!nodes[j]) {
                    ++size;
                }
            }
            totalCost += size;

            if (size == 0) {
                break;
            }

            int x = dis(gen);
            while (nodes[x]) {
                x = dis(gen);
            }

            nodes[x] = 1;
            vector<int> component;
            for (int j = 0; j < n; ++j) {
                if (!nodes[j]) {
                    dfs(j);
                    component.push_back(j);
                    break;
                }
            }
            components.push_back(component);

            for (int j = 0; j < n; ++j) {
                nodes[j] = 0;
            }
            for (int j = 0; j < components.size(); ++j) {
                for (int k = 0; k < components[j].size(); ++k) {
                    nodes[components[j][k]] = 1;
                }
            }
        }
        ans += totalCost;
    }
    return ans / 1000000.0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cout << fixed;
    cout.precision(15);
    cout << solve(n) << endl;
    return 0;
}