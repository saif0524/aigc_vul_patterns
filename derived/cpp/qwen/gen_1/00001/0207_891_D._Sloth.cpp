#include <bits/stdc++.h>
using namespace std;

const int N = 500005;

vector<int> g[N];
int sz[N], cnt[N];
int n;

void dfs(int v, int p) {
    sz[v] = 1;
    cnt[v] = 0;
    for (int u : g[v]) {
        if (u == p) continue;
        dfs(u, v);
        sz[v] += sz[u];
        if (sz[u] % 2 == 0) cnt[v]++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=n-1;i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, -1);
    long long ans = 0;
    for(int i=1;i<=n;i++){
        int res = n - sz[i];
        if(res % 2 == 0) cnt[i]++;
        if(cnt[i] > 0){
            ans += 1LL * (cnt[i] - 1) * sz[i] * (n - sz[i]);
            ans += 1LL * sz[i] * (n - sz[i]);
        }
    }
    cout << ans;
    return 0;
}