#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N, P;
    cin >> N >> P;
    ll ans = 1;
    for(ll i = 2; i*i <= P; i++){
        ll cnt = 0;
        while(P % i == 0){
            cnt++;
            P /= i;
        }
        ans *= pow(i, cnt / N);
    }
    if(P > 1){
        ans = max(ans, (ll)1);
    }
    cout << ans;
}