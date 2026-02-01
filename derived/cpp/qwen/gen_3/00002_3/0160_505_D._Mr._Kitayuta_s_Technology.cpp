#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> inDeg(n+1, 0);
    vector<int> outDeg(n+1, 0);
    while(m--){
        int u, v;
        cin >> u >> v;
        outDeg[u]++;
        inDeg[v]++;
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        if(outDeg[i] == 0){
            ans++;
        }
        if(inDeg[i] == 0){
            ans++;
        }
    }
    cout << ans - (inDeg[1] == 0 && outDeg[1] == 0) << "\n";
    return 0;
}