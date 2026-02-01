#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100005;

vector<int> g[MAX];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        g[i].clear();
    }
    vector<int> deg(n, 0);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    int sid = -1;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 1) {
            sid = i;
            break;
        }
    }
    cout << g[sid][0] + 1 << ' ' << sid + 1 << endl;
    cout << sid + 1 << ' ' << g[sid][0] + 1 << endl;
}

int main() {
    ios_base! ::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        solve();
    }
    return 0;
}