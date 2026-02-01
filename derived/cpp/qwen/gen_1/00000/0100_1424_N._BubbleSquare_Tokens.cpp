#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> deg(n+1, 0);
    vector<pair<int, int>> edges(k);
    for(int i=0;i<k;i++){
        cin >> edges[i].first >> edges[i].second;
        deg[edges[i].first]++;
        deg[edges[i].second]++;
    }
    set<int> s;
    for(int i=1;i<=n;i++){
        s.insert(deg[i]);
    }
    int cnt=0;
    vector<int> keep;
    for(int i=1;i<=n;i++){
        if(s.count(deg[i])){
            cnt++;
            keep.push_back(i);
            s.erase(deg[i]);
        }
    }
    cout << cnt << "\n";
    for(int i=0;i<cnt;i++){
        cout << keep[i] << " ";
    }
    cout << "\n";
    vector<int> ans(k, 0);
    set<int> used;
    for(int i=0;i<k;i++){
        if(!used.count(edges[i].first) && !used.count(edges[i].second)){
            if(deg[edges[i].first] > deg[edges[i].second]){
                ans[i] = 1;
                used.insert(edges[i].second);
            }
            else if(deg[edges[i].first] < deg[edges[i].second]){
                ans[i] = 2;
                used.insert(edges[i].first);
            }
            else{
                ans[i] = 1;
                used.insert(edges[i].second);
            }
        }
    }
    for(int i=0;i<k;i++){
        cout << edges[i].first << " " << edges[i].second << " " << ans[i] << "\n";
    }
}