#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

struct SegmentTree {
    int n;
    vector<int> tree;

    SegmentTree(int n) : n(n), tree(4 * n, 0) {}

    void update(int idx, int val) {
        update(0, 0, n - 1, idx, val);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node + 1, start, mid, idx, val);
            } else {
                update(2 * node + 2, mid + 1, end, idx, val);
            }
            tree[node] = (tree[2 * node + 1] + tree[2 * node + 2]) % MOD;
        }
    }

    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    int query(int node, int start, int end, int l, int r) {
        if (l > end || r < start) {
            return 0;
        } else if (l <= start && end <= r) {
            return tree[node];
        } else {
            int mid = (start + end) / 2;
            return (query(2 * node + 1, start, mid, l, r) + query(2 * node + 2, mid + 1, end, l, r)) % MOD;
        }
    }
};

int powmod(int a, int b, int mod) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = ((long long)res * a) % mod;
        }
        a = ((long long)a * a) % mod;
        b >>= 1;
    }
    return res;
}

int inv(int a, int mod) {
    return powmod(a, mod - 2, mod);
}

int fact(int n, int mod) {
    int res = 1;
    for (int i = 1; i <= n; ++i) {
        res = ((long long)res * i) % mod;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> intervals(n);
    for (auto& [l, r] : intervals) {
        cin >> l >> r;
    }

    sort(intervals.begin(), intervals.end());

    set<int> points;
    points.insert(0);
    points.insert(1000000000 + 1);
    for (const auto& [l, r] : intervals) {
        points.insert(l);
        points.insert(r);
    }

    vector<int> point(1000000000 + 2);
    int idx = 0;
    for (int p : points) {
        point[p] = idx++;
    }

    SegmentTree seg(point.size());
    seg.update(point[0], 1);

    int ans = 0;
    for (const auto& [l, r] : intervals) {
        for (int i = r - 1; i >= l; --i) {
            seg.update(point[i + 1], seg.query(point[l], point[i]) % MOD);
        }
        seg.update(point[r], (seg.query(point[l], point[r]) + MOD - seg.query(point[r], point[r]) % MOD) % MOD);
    }

    cout << seg.query(point[1000000001], point[1000000001]) % MOD << "\n";

    return 0;
}