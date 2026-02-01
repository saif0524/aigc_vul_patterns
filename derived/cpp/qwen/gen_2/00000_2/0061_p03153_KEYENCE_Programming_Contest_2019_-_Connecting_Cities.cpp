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
    for(auto &a : A) cin >> a;
    ll ans = 0;
    ll pref = 0;
    for(int i=1;i<N;i++){
        ll cost = min(D*i + A[i], D*(N-i) + A[i-1]);
        ans += cost;
        pref += cost;
    }
    ans -= min(D*(N-1) + A[N-1], D*(N-1) + A[0]);
    ll suf = 0;
    for(int i=N-2;i>=0;i--){
        ll cost = min(D*(N-i-1) + A[i], D*(N-i-1) + A[N-1]);
        suf += cost;
        ans = min(ans, pref + suf - min(D*(N-i-1) + A[i], D*(N-i-1) + A[N-1]));
    }
    cout << ans;
}