#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<set<int>> friends(n);
    vector<int> ans(m, 0);
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        friends[x].insert(y);
        friends[y].insert(x);
        for(auto &p : {x, y}){
            int cnt = 0;
            for(auto &f : friends[p]){
                if(friends[f].size() >= k){
                    cnt++;
                }
            }
            if(cnt >= k){
                ans[i] = max(ans[i], cnt + 1);
            }
        }
    }
    for(int i=0; i<m; i++){
        if(i > 0){
            ans[i] = max(ans[i], ans[i-1]);
        }
        cout << ans[i] << "\n";
    }
}