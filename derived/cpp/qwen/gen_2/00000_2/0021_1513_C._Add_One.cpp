#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

ll powmod(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = res * base % MOD;
        base = base * base % MOD;
        exp /= 2;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        ll length = 0;
        while(n > 0){
            int digit = n % 10;
            length = (length + powmod(10, m) * (digit + 1)) % MOD;
            n /= 10;
        }
        ll result = 0;
        ll current = 1;
        while(length > 0){
            result = (result + current * (length % 10)) % MOD;
            current = current * 10 % MOD;
            length /= 10;
        }
        cout << result << "\n";
    }
}