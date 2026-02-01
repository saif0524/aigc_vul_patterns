#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

ll power_mod(ll base, ll exp) {
    ll result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) result = result * base % MOD;
        base = base * base % MOD;
        exp /= 2;
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        if(n == 1 || n == 2){
            cout << 0 << "\n";
            continue;
        }
        ll ans = (power_mod(3, n-2) - 1 + MOD) % MOD;
        ans = (ans * 4) % MOD;
        cout << ans << "\n";
    }
}