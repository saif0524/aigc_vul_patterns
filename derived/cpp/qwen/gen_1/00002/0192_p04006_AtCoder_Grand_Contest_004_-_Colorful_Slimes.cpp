#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    ll x;
    cin >> N >> x;
    vector<ll> a(N);
    for(auto &ai: a) cin >> ai;
    
    if(N==2){
        cout << min(2*x, a[0]+a[1]) << "\n";
        return 0;
    }
    
    ll ans = accumulate(a.begin(), a.end(), 0LL);
    for(int i=0;i<N;++i){
        ll current = 0;
        for(int j=0;j<N;++j){
            if((i+j)%N != (N-1)){
                current += a[(i+j)%N];
            }
        }
        current += x;
        ans = min(ans, current);
    }
    cout << ans;
}