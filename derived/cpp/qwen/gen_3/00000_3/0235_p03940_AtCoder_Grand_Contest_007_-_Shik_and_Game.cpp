#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long N, E, T;
    cin >> N >> E >> T;
    vector<long long> x(N);
    for(auto &i : x) cin >> i;
    long long last_candy_time = 0;
    for(long long i = 0; i < N; ++i){
        last_candy_time = max(last_candy_time, x[i]) + T;
    }
    cout << max(last_candy_time, E);
    return 0;
}