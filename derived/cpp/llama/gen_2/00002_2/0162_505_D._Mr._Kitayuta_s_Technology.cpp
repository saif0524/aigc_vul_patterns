#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 5;

vector<int> g[MAXN];
int n, m;
int in[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        in[b]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }

    int ans = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            in[v]--;
            if (in[v] == 0) {
                q.push(v);
            }
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}