#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 4e5 + 5;
vector<int> g[N];
int sz[N], n;

void dfs(int v, int p = -1) {
    sz[v] = 1;
    for (int to : g[v]) {
        if (to != p) {
            dfs(to, v);
            sz[v] += sz[to];
        }
    }
}

bool check(int v, int p = -1) {
    int mx = 0;
    for (int to : g[v]) {
        if (to != p) {
            mx = max(mx, sz[to]);
        }
    }
    return mx <= n / 2;
}

bool check2(int v, int p = -1) {
    int cnt = 0;
    for (int to : g[v]) {
        if (to != p) {
            cnt += (sz[to] > n / 2);
        }
    }
    return cnt <= 1;
}

vector<int> get(int v, int p = -1) {
    vector<int> res;
    res.push_back(v);
    for (int to : g[v]) {
        if (to != p) {
            res.push_back(sz[to]);
        }
    }
    sort(res.begin(), res.end(), [](int x, int y) { return sz[x] > sz[y]; });
    return res;
}

bool check3(int v, int p = -1) {
    vector<int> c1 = get(v, p);
    vector<int> c2;
    for (int to : g[v]) {
        if (to != p) {
            c2 = get(to, v);
            if (c2.size() > 1 && c2[1] > n / 2) return false;
        }
    }
    for (int to : g[v]) {
        if (to != p) {
            int tmp = sz[v] - sz[to];
            if (tmp > n / 2) return false;
        }
    }
    if (c1.size() > 1 && (c1[0] + c1[1]) > n) return false;
    return true;
}

bool check4(int v, int p = -1) {
    for (int to : g[v]) {
        if (to != p) {
            int tmp = sz[v] - sz[to];
            if (tmp > n / 2) {
                int tmp2 = sz[to];
                if (tmp2 > n / 2) return false;
            }
        }
    }
    vector<int> c1 = get(v, p);
    if (c1.size() > 1 && c1[0] + c1[1] > n) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    for (int i = 1; i <= n; ++i) {
        bool ok = false;
        for (int j = 1; j <= n; ++j) {
            sz[j] = 0;
        }
        dfs(i);
        if (check(i)) ok = true;
        for (int j = 1; j <= n; ++j) {
            if (i != j) {
                for (int to : g[j]) {
                    if (to != i) {
                        sz[j] = 0;
                        dfs(j);
                        if (check(j)) ok = true;
                        for (int to2 : g[i]) {
                            if (to2 != j) {
                                sz[i] = 0;
                                sz[j] = 0;
                                dfs(i);
                                dfs(j);
                                if (check(i)) ok = true;
                                if (check(j)) ok = true;
                            }
                        }
                    }
                }
            }
        }
        cout << ok << ' ';
    }
    return 0;
}