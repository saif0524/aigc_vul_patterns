#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int MAXN = 100005;
const int MAXQ = 100005;

ll fib[2*MAXN];
ll BIT1[MAXN];
ll BIT2[MAXN];
int n, m;

void add(ll BIT[], int idx, ll val) {
    while (idx <= n) {
        BIT[idx] = (BIT[idx] + val) % MOD;
        idx += (idx & (-idx));
    }
}

ll sum(ll BIT[], int idx) {
    ll res = 0;
    while (idx > 0) {
        res = (res + BIT[idx]) % MOD;
        idx -= (idx & (-idx));
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i < 2*MAXN; i++) fib[i] = (fib[i-1] + fib[i-2]) % MOD;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        add(BIT1, i, a);
        add(BIT2, i, a*a);
    }
    while(m--){
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 1){
            ll x;
            cin >> x;
            add(BIT1, l, x);
            add(BIT1, r+1, -x);
            add(BIT2, l, x*x);
            add(BIT2, r+1, -x*x);
        }
        else{
            ll sum1 = sum(BIT1, r) - sum(BIT1, l-1);
            ll sum2 = sum(BIT2, r) - sum(BIT2, l-1);
            ll num = (sum1*sum1 - sum2 + MOD) % MOD;
            ll den = 2;
            num = (num * den) % MOD;
            num = (num + MOD) % MOD;
            cout << fib[num] << "\n";
        }
    }
}