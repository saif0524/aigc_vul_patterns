#include <bits/stdc++.h>
using namespace std;

struct Node {
    int max_val;
    int lazy;
};

void build(vector<Node>& tree, vector<int>& a, int node, int start, int end) {
    if (start == end) {
        tree[node].max_val = a[start];
    } else {
        int mid = (start + end) / 2;
        build(tree, a, 2 * node, start, mid);
        build(tree, a, 2 * node + 1, mid + 1, end);
        tree[node].max_val = max(tree[2 * node].max_val, tree[2 * node + 1].max_val);
    }
}

void update_range(vector<Node>& tree, int node, int start, int end, int l, int r, int val) {
    if (tree[node].lazy != 0) {
        tree[node].max_val = max(tree[node].max_val, tree[node].lazy);
        if (start != end) {
            tree[2 * node].lazy = max(tree[2 * node].lazy, tree[node].lazy);
            tree[2 * node + 1].lazy = max(tree[2 * node + 1].lazy, tree[node].lazy);
        }
        tree[node].lazy = 0;
    }
    if (start > end or start > r or end < l)
        return;

    if (start >= l and end <= r) {
        tree[node].max_val = max(tree[node].max_val, val);
        if (start != end) {
            tree[2 * node].lazy = max(tree[2 * node].lazy, val);
            tree[2 * node + 1].lazy = max(tree[2 * node + 1].lazy, val);
        }
        return;
    }
    int mid = (start + end) / 2;
    update_range(tree, 2 * node, start, mid, l, r, val);
    update_range(tree, 2 * node + 1, mid + 1, end, l, r, val);
    tree[node].max_val = max(tree[2 * node].max_val, tree[2 * node + 1].max_val);
}

int query(vector<Node>& tree, int node, int start, int end, int idx) {
    if (start == end) {
        return tree[node].max_val;
    }
    if (tree[node].lazy != 0) {
        tree[node].max_val = max(tree[node].max_val, tree[node].lazy);
        tree[2 * node].lazy = max(tree[2 * node].lazy, tree[node].lazy);
        tree[2 * node + 1].lazy = max(tree[2 * node + 1].lazy, tree[node].lazy);
        tree[node].lazy = 0;
    }
    int mid = (start + end) / 2;
    if (idx >= start and idx <= mid) {
        return query(tree, 2 * node, start, mid, idx);
    } else {
        return query(tree, 2 * node + 1, mid + 1, end, idx);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    vector<Node> tree(4*n);
    build(tree, a, 1, 0, n-1);
    while(q--){
        int t, x, y;
        cin >> t >> x >> y;
        --x;
        if(t==1){
            update_range(tree, 1, 0, n-1, 0, x, y);
        } else {
            int ans = 0;
            int money = y;
            for(int i = x; i < n; ++i){
                int price = query(tree, 1, 0, n-1, i);
                if(money >= price){
                    ++ans;
                    money -= price;
                } else {
                    break;
                }
            }
            cout << ans << "\n";
        }
    }
}