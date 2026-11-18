// [esbmc] replaced #include <bits/stdc++.h> with ESBMC-compatible headers
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <istream>
#include <ostream>
#include <ios>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <streambuf>
#include <string>
#include <string_view>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <iterator>
#include <memory>
#include <tuple>
#include <limits>
#include <random>
#include <complex>
#include <valarray>
#include <stdexcept>
#include <exception>
#include <typeinfo>
#include <type_traits>
#include <initializer_list>
#include <numbers>
#include <any>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 100005;
const int MAXFIB = 2 * MAXN;

typedef long long ll;

ll fib[MAXFIB];

void precompute_fib() {
    fib= 0;
    fib= 1;
    for (int i =2; i < MAXFIB; ++i) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }
}

struct Node {
    ll sum;
    ll lazy;
};

Node segtree[4 * MAXN];

void push_down(int node, int l, int r) {
    if (segtree[node].lazy == 0) return;
    int mid = (l + r) / 2;
    segtree[node * 2].sum = (segtree[node * 2].sum + (mid - l + 1) * segtree[node].lazy) % MOD;
    segtree[node * 2+ 1].sum = (segtree[node * 2+1].sum + (r - mid) * segtree[node].lazy) % MOD;
    segtree[node *2].lazy = (segtree[node * 2].lazy + segtree[node].lazy) % MOD;
    segtree[node *2 +1].lazy = (segtree[node *2 + 1].lazy + segtree[node].lazy) % MOD;
    segtree[node].lazy = 0;
}

void update(int node, int l, int r, int ql, int qr, ll val) {
    if (qr < l || r < ql) return;
    if (ql <= l && r <= qr) {
        segtree[node].sum = (segtree[node].sum + (r - l + 1) * val) % MOD;
        segtree[node].lazy = (segtree[node].lazy + val) % MOD;
        return;
    }
    push_down(node, l, r);
    int mid = (l + r) / 2;
    update(node * 2, l, mid, ql, qr, val);
    update(node * 2 +1, mid + 1, r, ql, qr, val);
    segtree[node].sum = (segtree[node * 2].sum + segtree[node *2 + 1].sum) % MOD;
}

ll query(int node, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return0;
    if (ql <= l && r <= qr) return segtree[node].sum;
    push_down(node, l, r);
    int mid = (l + r) / 2;
    return (query(node * 2, l, mid, ql, qr) + query(node * 2 +1, mid + 1, r, ql, qr)) % MOD;
}

int main(){
    ((void)0);
    ((void)0);
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for(auto &x: a) cin >> x;
    precompute_fib();
    for(int i=0;i<n;i++){
        update(1, 0, n-1, i, i, a[i]);
    }
    for(int i=0;i<m;i++){
        int t, l, r;
        cin >> t >> l >> r;
        l--; r--;
        if(t==1){
            ll x;
            cin >> x;
            update(1, 0, n-1, l, r, x);
        }
        else{
            ll sum = query(1, 0, n-1, l, r);
            cout << fib[sum] << "\n";
        }
    }
}