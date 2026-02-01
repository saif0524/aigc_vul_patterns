#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, q;
    cin >> n >> k >> q;
    vector<long long> t(n);
    for(auto &x: t) cin >> x;
    set<pair<long long, int>> online;
    vector<bool> isOnline(n+1, false);
    for(int i=0;i<q;++i){
        int type, id;
        cin >> type >> id;
        if(type==1){
            if(online.size() < k){
                online.insert({t[id-1], id});
                isOnline[id] = true;
            }else{
                auto it = online.begin();
                if(t[id-1] > (*it).first){
                    isOnline[(*it).second] = false;
                    isOnline[id] = true;
                    online.erase(it);
                    online.insert({t[id-1], id});
                }
            }
        }else{
            if(isOnline[id]) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}