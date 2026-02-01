#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    ll D;
    cin >> N >> D;
    vector<ll> A(N);
    for(auto &a: A) cin >> a;
    
    ll total = accumulate(A.begin(), A.end(), 0LL);
    ll ans = 0;
    ll left_sum = 0;
    for(int i=0; i<N-1; i++){
        left_sum += A[i];
        ans += D * (total - left_sum - A[i]) + A[i]*(N-i-1) - (total - left_sum - A[i])*i;
    }
    cout << ans << "\n";
}