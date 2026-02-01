#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long modulo = 1000000007;

int n, m;
vector<int> h;
vector<int> outd;
vector<vector<int>> edg;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    h.resize(n);
    outd.resize(n, 0);
    edg.resize(n);

    for (int i = 0; i < n; ++i) cin >> h[i];
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edg[u].push_back(v);
        outd[u]++;
    }

    vector<int> x(n, -1);
    for (int s = 0; s < n; ++s) {
        if (outd[s]) continue;
        int sr = s;
        while (sr >= 0) {
            if (x[sr] == -1) x[sr] = 0;
            sr = x[sr];
        }
    }

    for (int s = 0; s < n; ++s) {
        if (outd[s] == 0) continue;
        vector<int> comp;
        vector<bool> used(n, false);
        int sr = s;
        while (sr >= 0 && !used[sr]) {
            used[sr] = true;
            comp.push_back(sr);
            sr = x[sr];
        }
        if (sr == -1) sr = s;
        int t = h[sr];
        for (int v : comp)
            t = (t ^ h[v]);
        if (t) {
            cout << "WIN\n";
            fill(h.begin(), h.end(), 0);
            h[sr] = t;
            for (int i = 0; i < n; ++i) cout << h[i] << " ";
            return 0;
        }
    }
    cout << "LOSE";
    return 0;
}