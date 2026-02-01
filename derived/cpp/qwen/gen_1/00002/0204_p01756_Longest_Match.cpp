#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string S;
    cin >> S;
    int m;
    cin >> m;
    
    map<string,vector<int>> startIdx;
    map<string,vector<int>> endIdx;
    int n = S.size();
    
    for(int i=0;i<n;i++){
        for(int j=1;j<=n-i;j++){
            string sub = S.substr(i,j);
            if(startIdx.find(sub)==startIdx.end()){
                startIdx[sub] = {i};
            } else {
                startIdx[sub].push_back(i);
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=1;j<=n-i;j++){
            string sub = S.substr(i,j);
            if(endIdx.find(sub)==endIdx.end()){
                endIdx[sub] = {i};
            } else {
                endIdx[sub].push_back(i);
            }
        }
    }
    
    while(m--){
        string x, y;
        cin >> x >> y;
        int ans = 0;
        if(startIdx.find(x)!=startIdx.end() && endIdx.find(y)!=endIdx.end()){
            for(int st:startIdx[x]){
                for(int en:endIdx[y]){
                    if(st<=en && x+y==S.substr(st,y.empty()?x.size():S.substr(st,en-st+1).size())){
                        ans = max(ans,y.empty()?x.size():en-st+1);
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}