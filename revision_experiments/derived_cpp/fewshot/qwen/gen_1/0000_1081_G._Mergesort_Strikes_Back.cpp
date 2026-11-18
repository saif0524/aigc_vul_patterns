#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mod_exp(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp >>= 1;
        base = (base * base) % mod;
    }
    return result;
}

ll mod_inv(ll a, ll p) {
    return mod_exp(a, p - 2, p);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k, q;
    cin >> n >> k >> q;
    vector<ll> fact(n+1, 1);
    vector<ll> inv_fact(n+1, 1);
    for(int i = 2; i <= n; ++i){
        fact[i] = (fact[i-1] * i) % q;
        inv_fact[i] = mod_inv(fact[i], q);
    }
    ll total_inversions = 0;
    for(int i = 1; i <= n; ++i){
        ll ways = fact[n];
        ways = (ways * inv_fact[i]) % q;
        ways = (ways * inv_fact[n-i]) % q;
        if(k == 0){
            total_inversions = (total_inversions + (ways * (n-i) * i /2) % q) % q;
        }
        else{
            ll sum = 0;
            for(int j =0; j <= min(i, k); ++j){
                ll curr = fact[i];
                curr = (curr * inv_fact[j]) % q;
                curr = (curr * inv_fact[i-j]) % q;
                curr = (curr * fact[n-i]) % q;
                curr = (curr * inv_fact[min(k-j, n-i)]) % q;
                curr = (curr * inv_fact[max(0, n-i-(k-j))]) % q;
                if((i-j) % 2 == 0)
                    sum = (sum + curr) % q;
                else
                    sum = (sum - curr + q) % q;
            }
            total_inversions = (total_inversions + (ways * sum * i * (n-i)) % q) % q;
        }
    }
    ll total_permutations = fact[n];
    ll inv_total_permutations = mod_inv(total_permutations, q);
    total_inversions = (total_inversions * inv_total_permutations) % q;
    cout << total_inversions << "\n";
    return 0;
}