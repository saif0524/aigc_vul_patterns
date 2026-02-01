#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, q;
    cin >> n >> k >> q;
    vector<long long> t(n);
    for(auto &ti : t) cin >> ti;
    vector<bool> online(n);
    set<pair<long long, int>> displayed;
    for(int qi=0; qi<q; ++qi){
        int type, id;
        cin >> type >> id;
        --id;
        if(type == 1){
            online[id] = true;
            displayed.insert({t[id], id});
            if(displayed.size() > k){
                int to_remove = (*displayed.begin()).second;
                displayed.erase(displayed.begin());
                online[to_remove] = false;
            }
        }
        else{
            if(online[id] && displayed.count({t[id], id}) > 0) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}