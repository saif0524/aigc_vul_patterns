#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node {
    ll sum;
    int min_weight;
};

Node merge(Node a, Node b) {
    return {a.sum + b.sum, min(a.min_weight, b.min_weight)};
}

Node identity = {0, INT_MAX};

Node apply(Node a, Node b) {
    if (b.sum == 0) return b;
    return {a.sum + b.sum, min(a.min_weight, b.min_weight)};
}

Node neutrl = {0, 0};

struct SegTree {
    Node t[4 * 100100];
    int n;

    void build(vector<Node> &a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = merge(t[v*2], t[v*2+1]);
        }
    }

    void build(vector<Node> &a) {
        n = (int)a.size();
        build(a, 1, 0, n-1);
    }

    Node query(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return identity;
        if (l == tl && r == tr) 
            return t[v];
        int tm = (tl + tr) / 2;
        return merge(query(v*2, tl, tm, l, min(r, tm)),
                     query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }

    Node query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }

    void modify(int v, int tl, int tr, int pos, Node new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                modify(v*2, tl, tm, pos, new_val);
            else
                modify(v*2+1, tm+1, tr, pos, new_val);
            t[v] = merge(t[v*2], t[v*2+1]);
        }
    }

    void modify(int pos, Node new_val) {
        modify(1, 0, n-1, pos, new_val);
    }
};

const int MAXN = 1e5 + 5;

vector<int> f, nxt[MAXN];
vector<ll> w;
vector<Node> nodes;
ll k;
SegTree seg;
int vis[MAXN], cycle_begin, cycle_size;
bool in_cycle[MAXN];

void find_cycle(int v) {
    for (int i = 0; i < MAXN; i++) vis[i] = 0;
    int u = v;
    do {
        vis[u] = 1;
        u = f[u];
    } while (!vis[u]);

    cycle_begin = u;
    cycle_size = 0;
    u = cycle_begin;
    do {
        u = f[u];
        ++cycle_size;
    } while (u != cycle_begin);

    u = cycle_begin;
    do {
        in_cycle[u] = true;
        u = f[u];
    } while (u != cycle_begin);
}

void preprocess(int n, int v) {
    nodes[v] = {w[v], w[v]};
    for (int to : nxt[v]) {
        preprocess(n, to);
        nodes[v] = apply(nodes[v], nodes[to]);
    }
}

void init(int n) {
    for (int i = 0; i < n; i++) {
        nxt[f[i]].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        if (!nodes[i].sum) {
            preprocess(n, i);
        }
    }
    for (int i = 0; i < n; i++) {
        if (in_cycle[i]) {
            int len = 0;
            ll sum = 0;
            int u = i;
            do {
                sum += w[u];
                u = f[u];
                ++len;
            } while (u != i);
            ll k_sum = k / len * sum;
            int k_rem = k % len;
            ll s = k_sum;
            ll m = INT_MAX;
            u = i;
            for (int _ = 0; _ < k_rem; _++) {
                s += w[u];
                m = min(m, w[u]);
                u = f[u];
            }
            nodes[i] = {s, m};
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n >> k;
    f.resize(n);
    nodes.resize(n);
    w.resize(n);
    for(auto &x: f) cin >> x;
    for(auto &x: w) cin >> x;
    for(int i=0;i<n;i++){
        find_cycle(i);
        init(n);
    }
    seg.build(nodes);
    for(int i=0;i<n;i++){
        Node ans;
        if(!in_cycle[i]){
            ans = seg.query(i, n-1);
        }
        else{
            ans = seg.query(i, i + cycle_size - 1);
        }
        cout << ans.sum << " " << ans.min_weight << "\n";
    }
}