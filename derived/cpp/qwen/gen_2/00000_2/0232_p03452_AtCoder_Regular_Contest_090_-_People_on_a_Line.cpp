#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int id[MAXN], sz[MAXN], x[MAXN];
bool vis[MAXN];

int find(int a) {
    if (id[a] == a) return a;
    return id[a] = find(id[a]);
}

void uni(int a, int b, int d) {
    a = find(a), b = find(b);
    if (a == b) return;
    if (sz[a] > sz[b]) swap(a, b);
    id[a] = b;
    sz[b] += sz[a];
    x[a] = x[b] - d;
}

bool check(int a, int b, int d) {
    a = find(a), b = find(b);
    if (a != b) return false;
    return x[a] - x[b] == d;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) id[i]=i, sz[i]=1, x[i]=0, vis[i]=false;
    for(int i=0;i<m;i++){
        int l, r, d;
        cin >> l >> r >> d;
        if(vis[l] && vis[r] && !check(l, r, d)){
            cout << "No\n";
            return 0;
        }
        vis[l] = true;
        vis[r] = true;
        uni(l, r, d);
    }
    cout << "Yes\n";
}