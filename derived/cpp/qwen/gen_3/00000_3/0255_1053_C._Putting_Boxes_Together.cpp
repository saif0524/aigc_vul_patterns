#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

struct SegmentTree {
    long long *st;
    long long *lazy;
    int n;

    SegmentTree(int n) {
        this->n = n;
        st = new long long[4 * n]();
        lazy = new long long[4 * n]();
    }

    void propagate(int node, int l, int r) {
        if (lazy[node] == 0) return;
        st[node] = ((r - l + 1) * lazy[node]) % MOD;
        if (l != r) {
            lazy[node * 2] = (lazy[node * 2] + lazy[node]) % MOD;
            lazy[node * 2 + 1] = (lazy[node * 2 + 1] + lazy[node]) % MOD;
        }
        lazy[node] = 0;
    }

    void update(int node, int l, int r, int ql, int qr, long long val) {
        propagate(node, l, r);
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            lazy[node] = val;
            propagate(node, l, r);
            return;
        }
        int m = (l + r) / 2;
        update(node * 2, l, m, ql, qr, val);
        update(node * 2 + 1, m + 1, r, ql, qr, val);
        st[node] = (st[node * 2] + st[node * 2 + 1]) % MOD;
    }

    long long query(int node, int l, int r, int ql, int qr) {
        propagate(node, l, r);
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return st[node];
        int m = (l + r) / 2;
        return (query(node * 2, l, m, ql, qr) + query(node * 2 + 1, m + 1, r, ql, qr)) % MOD;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<long long> w(n);
    for (int &x : a) cin >> x;
    for (long long &x : w) cin >> x;

    SegmentTree sumST(n);
    SegmentTree posSumST(n);

    for (int i = 0; i < n; i++) {
        sumST.update(1, 0, n - 1, i, i, w[i]);
        posSumST.update(1, 0, n - 1, i, i, 1LL * w[i] * a[i]);
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        if (x < 0) {
            int id = -x - 1;
            long long oldVal = w[id];
            long long newVal = y;
            w[id] = newVal;
            sumST.update(1, 0, n - 1, id, id, newVal - oldVal);
            posSumST.update(1, 0, n - 1, id, id, 1LL * (newVal - oldVal) * a[id]);
        } else {
            int l = x - 1;
            int r = y - 1;
            long long sum = sumST.query(1, 0, n - 1, l, r);
            long long posSum = posSumST.query(1, 0, n - 1, l, r);
            long long medianPos;
            long long prefixSum = 0;
            for (int i = l; i <= r; i++) {
                prefixSum = (prefixSum + w[i]) % MOD;
                if (prefixSum * 2 >= sum || i == r) {
                    medianPos = a[i];
                    break;
                }
            }
            long long result = (1LL * medianPos * sum - posSum + MOD) % MOD;
            cout << result << "\n";
        }
    }
    return 0;
}