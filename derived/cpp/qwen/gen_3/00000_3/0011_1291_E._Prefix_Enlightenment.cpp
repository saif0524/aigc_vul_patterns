#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 5;
vector<int> adj[MAXN];
int dsu[MAXN], sz[MAXN], on[MAXN], ans[MAXN];

int find(int x) {
    return dsu[x] < 0 ? x : dsu[x] = find(dsu[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    dsu[y] = x;
    sz[x] += sz[y];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for(int i=1;i<=n;i++){
        dsu[i] = -1;
        sz[i] = 1;
        on[i] = (s[i-1] == '1');
    }
    for(int i=0;i<k;i++){
        int c;
        cin >> c;
        vector<int> v(c);
        for(auto &x: v) cin >> x;
        int root = find(v[0]);
        for(auto &x: v){
            merge(root, x);
            adj[root].push_back(x);
        }
    }
    for(int i=1;i<=n;i++){
        if(dsu[i] < 0){
            int total = 0, ones = 0;
            for(auto &x: adj[i]){
                total++;
                ones += on[x];
            }
            int need = (total + 1) / 2;
            if(ones < need){
                for(auto &x: adj[i]){
                    on[x] ^= 1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        int root = find(i);
        ans[i] = ans[i-1] + (on[i] == 0);
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << "\n";
    }
}