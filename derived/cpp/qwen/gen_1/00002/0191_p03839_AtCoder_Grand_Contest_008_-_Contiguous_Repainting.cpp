#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long N, K;
    cin >> N >> K;
    vector<long long> a(N);
    for(long long &x: a) cin >> x;
    vector<long long> psum(N+1, 0);
    for(long long i=0; i<N; i++){
        psum[i+1] = psum[i] + a[i];
    }
    vector<long long> dp(N+1, 0);
    deque<long long> dq;
    for(long long i=1; i<=N; i++){
        while(!dq.empty() && dq.front() < i-K) dq.pop_front();
        long long best = dq.empty() ? 0 : dp[dq.front()];
        dp[i] = max(dp[i-1], best + psum[i] - psum[max(0LL, i-K)]);
        while(!dq.empty() && dp[i] >= dp[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }
    cout << max(0LL, dp[N]) << "\n";
}