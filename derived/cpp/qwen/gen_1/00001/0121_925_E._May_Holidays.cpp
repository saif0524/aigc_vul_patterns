#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> parents, subordinates, limits, affected;
int n, m, dis_cnt = 0;

void preprocess(int cur, int parent) {
    parents[cur] = parent;
    for(int nxt : adj[cur]) {
        preprocess(nxt, cur);
        subordinates[cur] += subordinates[nxt] + 1;
    }
    affected[cur] = subordinates[cur] > limits[cur];
    dis_cnt += affected[cur];
}

void update(int cur) {
    if(affected[cur]) {
        dis_cnt--;
        affected[cur] = false;
    }
    int new_val = subordinates[cur] - (limits[cur] + 1);
    if(new_val > 0) {
        dis_cnt++;
        affected[cur] = true;
    }
    if(cur == 1) return;
    update(parents[cur]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    adj.resize(n + 1);
    parents.resize(n + 1);
    subordinates.resize(n + 1, 0);
    limits.resize(n + 1);
    affected.resize(n + 1, false);
    
    for(int i=2; i<=n; i++){
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    
    for(int i=1; i<=n; i++) cin >> limits[i];
    preprocess(1, 1);
    
    vector<int> ans(m);
    for(int i=0; i<m; i++){
        int q;
        cin >> q;
        q = abs(q);
        update(q);
        ans[i] = dis_cnt;
    }
    
    for(int a : ans) cout << a << " ";
    cout << "\n";
    return 0;
}