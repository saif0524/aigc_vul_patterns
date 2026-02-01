#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll N, P;
    cin >> N >> P;
    ll ans = 1;
    for(ll i=2;i*i<=P;i++){
        ll cnt = 0;
        while(P % i == 0){
            P /= i;
            cnt++;
        }
        if(cnt >= N){
            ll div = cnt / N;
            ans = max(ans, ll(pow(i, div)));
        }
    }
    if(P > 1){
        ans = max(ans, P);
    }
    cout << ans;
}