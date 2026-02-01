#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 200005;

int n, p[MAXN], pos[MAXN];

struct SegmentTree {
    int tree[4 * MAXN], lazy[4 * MAXN];

    void update(int node, int start, int end, int l, int r, int val) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node];
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (start > r || end < l) return;
        if (start >= l && end <= r) {
            tree[node] += val;
            if (start != end) {
                lazy[2 * node] += val;
                lazy[2 * node + 1] += val;
            }
            return;
        }
        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int start, int end, int l, int r) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node];
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (start > r || end < l) return INT_MAX;
        if (start >= l && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return min(query(2 * node, start, mid, l, r), query(2 * node + 1, mid + 1, end, l, r));
    }
} segtree;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) segtree.tree[i] = segtree.lazy[i] = 0;
        ll ans = 0;
        for (int i = 1; i <= k; i++) {
            int p = pos[i];
            for (int j = 1; j < p; j++) {
                segtree.update(1, 1, n, j, p - 1, 1);
            }
            ans += segtree.query(1, 1, n, p, n);
        }
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}