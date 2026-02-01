#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;

vector<int> parent[MAXN], type[MAXN];

void init(int n) {
    for (int i = 0; i < n; i++) {
        parent[i].clear();
        type[i].clear();
    }
}

void dfs(int u, int p, int t, bool specialCase) {
    if (specialCase) {
        parent[u].push_back(p);
        type[u].push_back(t);
    }
    for (int i = 0; i < parent[u].size(); i++) {
        int v = parent[u][i];
        int tt = type[u][i];
        if (tt == 0) {
            dfs(v, p, t, specialCase);
        } else if (tt == 1 && !specialCase) {
            dfs(v, p, t, specialCase);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    init(n);

    for (int i = 0; i < n; i++) {
        int p, t;
        cin >> p >> t;
        if (p != -1) {
            parent[i].push_back(p - 1);
            type[i].push_back(t);
            dfs(i, p - 1, t, (t == 0));
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;
        u--; v--;
        bool flag = false;
        if (t == 1) {
            for (int i = 0; i < parent[v].size(); i++) {
                if (parent[v][i] == u && type[v][i] == 0) {
                    flag = true;
                    break;
                }
            }
        } else {
            for (int i = 0; i < parent[v].size(); i++) {
                if (parent[v][i] == u && type[v][i] == 1) {
                    flag = true;
                    break;
                }
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }

    return 0;
}