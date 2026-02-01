#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    
    vector<bool> possible(n+1, true);
    for(int i=1;i<=n;i++){
        if(a[i]>0){
            possible[a[i]] = false;
        }
    }
    
    vector<bool> seen(n+1, false);
    function<void(int)> dfs = [&](int node){
        if(seen[node]) return;
        seen[node] = true;
        if(a[node]>0) dfs(a[node]);
    };
    dfs(x);
    
    vector<int> result;
    for(int i=1;i<=n;i++){
        if(possible[i] && seen[i]){
            result.push_back(i);
        }
    }
    
    for(auto pos : result){
        cout << pos << "\n";
    }
    
    return 0;
}