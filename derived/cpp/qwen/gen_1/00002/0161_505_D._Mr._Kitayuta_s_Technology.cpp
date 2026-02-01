#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> in_degree(n+1, 0);
    vector<int> out_degree(n+1, 0);
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        out_degree[u]++;
        in_degree[v]++;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(in_degree[i] == 0){
            ans++;
        }
    }
    cout << ans;
    return 0;
}