#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> deg(n + 1, 0);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }
    int leaf_count = 0;
    for(int i=1; i<=n; i++){
        if(deg[i]==1) leaf_count++;
    }
    if(leaf_count >= 3) cout << "NO";
    else cout << "YES";
}