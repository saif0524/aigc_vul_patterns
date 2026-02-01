#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long N, M;
    cin >> N >> M;
    vector<long long> A(N);
    for(auto &a : A) cin >> a;
    
    vector<long long> prefix(N+1, 0);
    for(long long i=0; i<N; i++){
        prefix[i+1] = (prefix[i] + A[i]) % M;
    }
    
    map<long long, long long> count;
    long long ans = 0;
    for(long long i=0; i<=N; i++){
        ans += count[prefix[i]];
        count[prefix[i]]++;
    }
    
    cout << ans;
}