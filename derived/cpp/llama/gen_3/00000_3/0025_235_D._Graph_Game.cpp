#include <iostream>
#include <vector>
#include <random>

using namespace std;

const int MAX_N = 3005;

struct Edge {
    int to, next;
};

Edge edges[MAX_N * 2];
int head[MAX_N], tot;

void addEdge(int u, int v) {
    edges[++tot] = {v, head[u]};
    head[u] = tot;
}

int n;
bool vis[MAX_N];

double dfs(int x) {
    vis[x] = true;
    int cnt = 1;
    for (int i = head[x]; i; i = edges[i].next) {
        int y = edges[i].to;
        if (!vis[y]) {
            cnt += dfs(y);
        }
    }
    return 1.0 * cnt * (cnt - 1) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, n - 1);

    const int numSamples = 1000000;
    double sum = 0.0;
    for (int i = 1; i <= numSamples; i++) {
        for (int j = 0; j < n; j++) {
            vis[j] = false;
        }
        double res = 0.0;
        for (int j = n; j >= 1; j--) {
            int x = dis(gen);
            while (vis[x]) {
                x = dis(gen);
            }
            res += j;
            vis[x] = true;
            for (int k = head[x]; k; k = edges[k].next) {
                int y = edges[k].to;
                if (!vis[y]) {
                    vis[y] = true;
                }
            }
        }
        sum += res;
    }

    cout << fixed << sum / numSamples << endl;

    return 0;
}