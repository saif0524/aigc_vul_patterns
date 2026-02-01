#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXM = 3e5 + 5;

int p[MAXN];
bool active[MAXM];
vector<int> conn[MAXN];
int dsu_par[MAXN], dsu_rank[MAXN];
bool dsu_active[MAXN];
pair<int, int> dsu_max[MAXN];

int dsu_get_par(int x) {
    if (x == dsu_par[x]) return x;
    return dsu_par[x] = dsu_get_par(dsu_par[x]);
}

void dsu_union(int x, int y) {
    x = dsu_get_par(x), y = dsu_get_par(y);
    if (x == y) return;
    if (dsu_rank[x] < dsu_rank[y]) swap(x, y);
    dsu_rank[x] += (dsu_rank[x] == dsu_rank[y]);
    dsu_max[x] = max(dsu_max[x], dsu_max[y]);
    dsu_par[y] = x;
    dsu_active[x] = dsu_active[x] | dsu_active[y];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; ++i){
        cin >> p[i];
        dsu_par[i] = i;
        dsu_rank[i] = 0;
        dsu_active[i] = true;
        dsu_max[i] = {p[i], i};
    }
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;
        conn[a].push_back({b, i});
        conn[b].push_back({a, i});
        active[i] = true;
    }
    for(int i = 1; i <= m; ++i){
        int a = conn[i][0].first, b = conn[i][0].second;
        if(active[i]){
            dsu_union(a, b);
        }
    }
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int v;
            cin >> v;
            v = dsu_get_par(v);
            if(dsu_active[v]){
                cout << dsu_max[v].first << "\n";
                dsu_max[v].first = 0;
            }
            else{
                cout << "0\n";
            }
        }
        else if(type == 2){
            int e;
            cin >> e;
            int a = conn[e][0].first, b = conn[e][0].second;
            if(active[e]){
                dsu_union(a, b);
                active[e] = false;
            }
        }
    }
}