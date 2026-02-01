#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n+1);
    vector<int> degree(n+1, 0);
    for(int i=1;i<=n;i++){
        cin >> p[i];
        if(p[i] != 0){
            degree[i]++;
            degree[p[i]]++;
        }
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(degree[i] % 2 == 0 && degree[i] > 0){
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans.push_back(u);
        degree[u] = 0;
        if(p[u] != 0){
            degree[p[u]]--;
            if(degree[p[u]] % 2 == 0 && degree[p[u]] > 0){
                q.push(p[u]);
            }
        }
    }
    if(ans.size() == n){
        cout << "YES\n";
        for(int x : ans){
            cout << x << "\n";
        }
    }
    else{
        cout << "NO\n";
    }
}