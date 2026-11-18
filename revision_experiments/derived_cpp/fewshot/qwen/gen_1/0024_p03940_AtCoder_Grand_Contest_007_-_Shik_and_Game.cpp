#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    long long E, T;
    cin >> N >> E >> T;
    vector<long long> x(N);
    for(auto &xi: x) cin >> xi;
    
    long long ans = 0;
    long long last_pos = 0;
    for(int i=0;i<N;i++){
        long long dist_to_bear = x[i] - last_pos;
        long long time_to_collect_coin = x[i] + T;
        ans = max(ans, time_to_collect_coin) + (E - x[i]);
        last_pos = x[i];
    }
    cout << ans;
}