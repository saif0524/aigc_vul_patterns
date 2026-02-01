#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long N, E, T;
    cin >> N >> E >> T;
    vector<long long> x(N);
    for(auto &xi: x) cin >> xi;
    long long ans = max(E, (x[0] + T));
    for(long long i=1;i<N;i++){
        long long time_to_give_coin = max(ans, x[i] + T);
        ans = max(ans, time_to_give_coin) + (x[i] - x[i-1]);
    }
    cout << ans + (E - x[N-1]);
}