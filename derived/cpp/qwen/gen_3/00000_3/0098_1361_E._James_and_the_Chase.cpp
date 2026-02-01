#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

vector<int> g[MAXN];
vector<int> g_rev[MAXN];
int in_deg[MAXN];
int out_deg[MAXN];
int comp[MAXN];
bool vis[MAXN];
stack<int> stk;
int n, m, tc;
int dfs_cnt;
int comp_cnt;

void dfs1(int v) {
    vis[v] = true;
    for (int u : g[v]) {
        if (!vis[u]) {
            dfs1(u);
        }
    }
    stk.push(v);
}

void dfs2(int v) {
    comp[v] = comp_cnt;
    vis[v] = true;
    for (int u : g_rev[v]) {
        if (!vis[u]) {
            dfs2(u);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> tc;
    while(tc--){
        cin >> n >> m;
        for(int i=1;i<=n;i++) g[i].clear(), g_rev[i].clear(), in_deg[i]=0, out_deg[i]=0;
        while(!stk.empty()) stk.pop();
        memset(comp, 0, sizeof comp);
        dfs_cnt = comp_cnt = 0;
        for(int i=0;i<m;i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g_rev[v].push_back(u);
            in_deg[v]++;
            out_deg[u]++;
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs1(i);
            }
        }
        memset(vis, false, sizeof vis);
        while(!stk.empty()){
            int v = stk.top(); stk.pop();
            if(!vis[v]){
                comp_cnt++;
                dfs2(v);
            }
        }
        bool can_be_interesting[MAXN];
        for(int i=1;i<=n;i++) can_be_interesting[i] = false;
        for(int i=1;i<=n;i++){
            if(in_deg[i]==0 && out_deg[i]==1) can_be_interesting[i] = true;
        }
        int interesting_cnt = 0;
        for(int i=1;i<=n;i++){
            if(can_be_interesting[i]){
                interesting_cnt++;
            }
        }
        for(int i=1;i<=n;i++){
            if(can_be_interesting[i]){
                for(int v : g[i]){
                    if(comp[i] != comp[v]){
                        interesting_cnt--;
                    }
                }
            }
        }
        vector<int> ans;
        for(int i=1;i<=n;i++){
            if(can_be_interesting[i]){
                bool good = true;
                for(int v : g[i]){
                    if(comp[i] != comp[v]){
                        good = false;
                    }
                }
                if(good) ans.push_back(i);
            }
        }
        if((int)ans.size() < (n + 4) / 5){
            cout << -1 << "\n";
        }
        else{
            for(auto &x : ans) cout << x << " ";
            cout << "\n";
        }
    }
}