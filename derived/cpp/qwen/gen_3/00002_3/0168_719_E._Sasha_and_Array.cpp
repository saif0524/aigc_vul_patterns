#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 100005;

long long fib[MAXN];

void precompute_fib() {
    fib[1] = 1, fib[2] = 1;
    for (int i = 3; i < MAXN; ++i) {
        fib[i] = (fib[i-1] + fib[i-2]) % MOD;
    }
}

struct FenwickTree {
    int n;
    vector<long long> bit;

    FenwickTree(int n) : n(n), bit(n+1) {}

    void update(int idx, long long delta) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += delta;
            bit[idx] %= MOD;
        }
    }

    long long query(int idx) {
        long long sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
            sum %= MOD;
        }
        return sum;
    }

    long long query(int l, int r) {
        return (query(r) - query(l-1) + MOD) % MOD;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    precompute_fib();
    
    vector<long long> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    
    FenwickTree ft(n);
    for(int i=1;i<=n;i++) ft.update(i, a[i]);
    
    while(m--){
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 1){
            long long x;
            cin >> x;
            ft.update(l, x);
            if(r < n) ft.update(r+1, -x);
        }
        else{
            long long sum = ft.query(l, r);
            cout << fib[sum] << "\n";
        }
    }
}