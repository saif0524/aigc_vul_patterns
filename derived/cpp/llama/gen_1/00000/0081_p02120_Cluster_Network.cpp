#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MAX_N = 1e5 + 5;
vector<int> G[MAX_N];
vector<long long> W(MAX_N);
long long Sum[MAX_N];

int Find(int u) {
    if (u == Sum[u])
        return u;
    return Sum[u] = Find(Sum[u]);
}

void Union(int u, int v) {
    int pu = Find(u);
    int pv = Find(v);
    if (pu == pv) return;
    if (Sum[pu] > Sum[pv]) {
        Sum[pu] += Sum[pv];
        Sum[pv] = pu;
    } else {
        Sum[pv] += Sum[pu];
        Sum[pu] = pv;
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> W[i];
        Sum[i] = W[i];
    }

    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) Sum[j] = W[j];
        for (int j = 1; j <= N; j++) {
            for (auto v : G[j]) {
                Union(j, v);
            }
        }
        long long ans = -1e18;
        for (int j = 1; j <= N; j++) {
            if (j == i) continue;
            int root = Find(j);
            if (ans < Sum[root]) {
                ans = Sum[root];
            }
        }
        cout << ans << endl;
    }

    return 0;
}