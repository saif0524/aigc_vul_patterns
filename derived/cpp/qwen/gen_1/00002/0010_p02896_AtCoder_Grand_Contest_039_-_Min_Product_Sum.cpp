#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll modexp(ll base, ll exp, ll mod) {
    ll result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N, M, K, D;
    cin >> N >> M >> K >> D;
    vector<ll> row_min(K+1, 0), col_min(K+1, 0);
    for(int i=1; i<=K; ++i){
        row_min[i] = modexp(i, N, D);
        col_min[i] = modexp(i, M, D);
    }
    ll total_sum = 0;
    vector<ll> row_sums(K+1, 0);
    for(int i=1; i<=K; ++i){
        ll row_sum = 0;
        for(int j=1; j<=K; ++j){
            row_sum = (row_sum + row_min[j] * col_min[i]) % D;
        }
        row_sums[i] = row_sum;
    }
    for(int i=1; i<=K; ++i){
        for(int j=1; j<=K; ++j){
            total_sum = (total_sum + row_sums[i] * row_sums[j]) % D;
        }
    }
    ll factor = modexp(K, N*M - 2, D);
    total_sum = (total_sum * factor) % D;
    cout << total_sum;
}