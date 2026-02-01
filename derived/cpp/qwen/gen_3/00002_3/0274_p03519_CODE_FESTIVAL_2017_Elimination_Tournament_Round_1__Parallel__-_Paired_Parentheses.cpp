#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node {
    ll sum, inc, lazy;

    Node() : sum(0), inc(0), lazy(0) {}

    void apply(ll l, ll r, ll v) {
        sum += v * (r - l + 1);
        lazy += v;
        inc += v;
    }

    void push(ll l, ll m, Node &left, Node &right) {
        left.apply(l, m, lazy);
        right.apply(m + 1, r, lazy);
        lazy = 0;
    }
};

void build(int n, int s, int t, vector<Node> &tree, vector<ll> &arr) {
    if (s == t) {
        tree[n].sum = arr[s];
        return;
    }
    int m = (s + t) / 2;
    build(2 * n, s, m, tree, arr);
    build(2 * n + 1, m + 1, t, tree, arr);
    tree[n].sum = tree[2 * n].sum + tree[2 * n + 1].sum;
}

void update(int n, int s, int t, int l, int r, ll v, vector<Node> &tree) {
    if (l > t || r < s) {
        return;
    }
    if (l <= s && t <= r) {
        tree[n].apply(s, t, v);
        return;
    }
    int m = (s + t) / 2;
    tree[n].push(s, m, tree[2 * n], tree[2 * n + 1]);
    update(2 * n, s, m, l, r, v, tree);
    update(2 * n + 1, m + 1, t, l, r, v, tree);
    tree[n].sum = tree[2 * n].sum + tree[2 * n + 1].sum;
}

ll query(int n, int s, int t, int l, int r, vector<Node> &tree, vector<ll> &delta, int lvl = 0) {
    if (l > t || r < s) {
        return 0;
    }
    if (l <= s && t <= r) {
        return tree[n].sum + tree[n].inc + delta[lvl] * (t - s + 1);
    }
    int m = (s + t) / 2;
    tree[n].push(s, m, tree[2 * n], tree[2 * n + 1]);
    return query(2 * n, s, m, l, r, tree, delta, lvl + 1) +
           query(2 * n + 1, m + 1, t, l, r, tree, delta, lvl + 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    vector<ll> a(2*N), b(2*N);
    for(int i=0;i<2*N;i++) cin >> a[i];
    for(int i=0;i<2*N;i++) cin >> b[i];
    vector<Node> tree(4*2*N);
    vector<ll> arr(2*N);
    for(int i=0;i<2*N;i++) arr[i] = a[i]+b[i];
    build(1,0,2*N-1,tree,arr);
    auto go = [&](int d, int lo, int hi, int lvl){
        if(lo > hi) return;
        if(lo == hi){
            if(arr[lo] == a[lo]){
                delta[lvl] += b[lo] - a[lo];
            }
            return;
        }
        int mid = (lo+hi)/2;
        if(d == 0){
            go(0,lo,mid,lvl+1);
            go(1,mid+1,hi,lvl+1);
        }
        else{
            go(1,lo,mid,lvl+1);
            go(0,mid+1,hi,lvl+1);
        }
    };
    vector<ll> delta(2*N);
    go(0,0,2*N-1,0);
    while(Q--){
        int p;
        ll x, y;
        cin >> p >> x >> y;
        p--;
        ll diff = x + y - a[p] - b[p];
        a[p] = x;
        b[p] = y;
        update(1,0,2*N-1,p,p,diff,tree);
        auto score = [&](int d, int lo, int hi, int lvl){
            if(lo > hi) return 0LL;
            if(lo == hi){
                if(arr[lo] == a[lo]){
                    return b[lo] + delta[lvl] + tree[1].inc;
                }
                return a[lo] + delta[lvl] + tree[1].inc;
            }
            int mid = (lo+hi)/2;
            if(d == 0){
                auto l = score(0,lo,mid,lvl+1);
                auto r = score(1,mid+1,hi,lvl+1);
                return l + r;
            }
            else{
                auto l = score(1,lo,mid,lvl+1);
                auto r = score(0,mid+1,hi,lvl+1);
                return l + r;
            }
        };
        ll ans = score(0,0,2*N-1,0);
        cout << ans << "\n";
    }
}