#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    set<int> blocked;
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        blocked.insert(x);
    }
    vector<long long> a(k);
    for(auto &x: a) cin >> x;
    long long ans = LLONG_MAX;
    for(int l=1;l<=k;l++){
        long long cost = 0;
        int pos = 0;
        bool can = true;
        while(pos < n){
            int farthest = pos;
            for(int p = pos; p < min(n, pos + l + 1); p++){
                if(blocked.find(p) == blocked.end()){
                    farthest = p;
                }
            }
            if(farthest == pos){
                can = false;
                break;
            }
            cost += a[l-1];
            pos = farthest + 1;
        }
        if(can){
            ans = min(ans, cost);
        }
    }
    if(ans == LLONG_MAX){
        cout << -1;
    }
    else{
        cout << ans;
    }
    return 0;
}