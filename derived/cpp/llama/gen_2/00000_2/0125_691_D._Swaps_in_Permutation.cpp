#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 1e6 + 10;

int n, m;
int p[MAXN];
int fa[MAXN];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) fa[fx] = fy;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }
    vector<int> v[n + 1];
    for (int i = 1; i <= n; i++) {
        v[find(i)].push_back(p[i]);
        sort(v[find(i)].begin(), v[find(i)].end(), greater<int>());
    }
    for (int i = 1; i <= n; i++) {
        cout << v[find(i)].back() << " ";
        v[find(i)].pop_back();
    }

    return 0;
}