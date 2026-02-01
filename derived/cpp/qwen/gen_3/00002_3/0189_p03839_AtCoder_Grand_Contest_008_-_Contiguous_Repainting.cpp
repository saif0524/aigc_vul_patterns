#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long N, K;
    cin >> N >> K;
    vector<long long> a(N);
    for(auto &x : a) cin >> x;
    long long sum = 0, max_sum = 0;
    for(long long i = 0; i < N; i++){
        sum += a[i];
        if(i >= K) sum -= a[i - K];
        if(sum > 0) max_sum += sum;
        sum = max(sum, 0LL);
    }
    cout << max_sum;
}