#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, sx, sy;
    cin >> n >> sx >> sy;
    vector<pair<long long, long long>> pos(n);
    map<pair<long long, long long>, long long> cnt;
    for(auto& [x,y] : pos){
        cin >> x >> y;
        cnt[{x,y}]++;
    }
    set<long long> X, Y;
    for(auto& [x,y] : pos){
        X.insert(x);
        Y.insert(y);
    }
    X.insert(sx);
    Y.insert(sy);
    X.erase(sx);
    Y.erase(sy);
    long long ans = 0;
    pair<long long, long long> best;
    for(long long x : X){
        for(long long y : Y){
            long long cur = 0;
            for(auto& [px, py] : cnt){
                if(abs(sx-x)+abs(sy-y) == abs(px-x)+abs(py-y) + abs(sx-px) + abs(sy-py)){
                    cur += cnt[{px, py}];
                }
            }
            if(cur > ans){
                ans = cur;
                best = {x, y};
            }
        }
    }
    cout << ans << "\n" << best.first << " " << best.second;
}