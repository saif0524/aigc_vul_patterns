#include <bits/stdc++.h>
using namespace std;

struct Node {
    int min_val, count, lazy;
    int left, right;
};

const int MAXN = 100005;
Node segtree[4 * MAXN];
int arr[MAXN];

void build(int node, int start, int end) {
    segtree[node].left = start;
    segtree[node].right = end;
    if (start == end) {
        segtree[node].min_val = arr[start];
        segtree[node].count = 1;
        segtree[node].lazy = 0;
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        segtree[node].min_val = min(segtree[2 * node].min_val, segtree[2 * node + 1].min_val);
        segtree[node].count = 0;
        segtree[node].lazy = 0;
    }
}

void push_down(int node) {
    if (segtree[node].lazy != 0) {
        int mid = (segtree[node].left + segtree[node].right) / 2;
        int lazy = segtree[node].lazy;
        if (segtree[node].min_val > lazy) {
            segtree[2 * node].min_val -= lazy;
            segtree[2 * node].count = (segtree[2 * node].right - segtree[2 * node].left + 1) * (segtree[2 * node].min_val == 0);
            segtree[2 * node].lazy += lazy;
            segtree[2 * node + 1].min_val -= lazy;
            segtree[2 * node + 1].count = (segtree[2 * node + 1].right - segtree[2 * node + 1].left + 1) * (segtree[2 * node + 1].min_val == 0);
            segtree[2 * node + 1].lazy += lazy;
        }
        segtree[node].lazy = 0;
    }
}

void update(int node, int l, int r, int x) {
    if (segtree[node].right < l || segtree[node].left > r) return;
    if (segtree[node].left >= l && segtree[node].right <= r && segtree[node].min_val <= x) return;
    push_down(node);
    if (segtree[node].left >= l && segtree[node].right <= r) {
        if (segtree[node].min_val > x) {
            segtree[node].min_val -= x;
            segtree[node].count = (segtree[node].right - segtree[node].left + 1) * (segtree[node].min_val == 0);
            segtree[node].lazy += x;
        }
        return;
    }
    update(2 * node, l, r, x);
    update(2 * node + 1, l, r, x);
    segtree[node].min_val = min(segtree[2 * node].min_val, segtree[2 * node + 1].min_val);
    segtree[node].count = 0;
}

int query(int node, int l, int r, int x) {
    if (segtree[node].right < l || segtree[node].left > r) return 0;
    if (segtree[node].left >= l && segtree[node].right <= r) {
        if (segtree[node].min_val > x) return 0;
        if (segtree[node].min_val == x) return segtree[node].count;
    }
    push_down(node);
    int mid = (segtree[node].left + segtree[node].right) / 2;
    return query(2 * node, l, r, x) + query(2 * node + 1, l, r, x);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> arr[i];
    build(1, 1, n);
    for(int i = 0; i < m; ++i){
        int type, l, r, x;
        cin >> type >> l >> r >> x;
        if(type == 1){
            update(1, l, r, x);
        }
        else{
            cout << query(1, l, r, x) << '\n';
        }
    }
    return 0;
}