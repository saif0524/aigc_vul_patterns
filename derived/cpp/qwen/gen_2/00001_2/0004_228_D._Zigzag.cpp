#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    long long sum[2][7];
    Node() {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 7; ++j) {
                sum[i][j] = 0;
            }
        }
    }
};

void build(const vector<int> &arr, vector<Node> &tree, int v, int tl, int tr) {
    if (tl == tr) {
        for (int z = 2; z <= 6; ++z) {
            int pos = (tl - 1) % z;
            tree[v].sum[0][z] += arr[tl - 1] * (pos + 1);
            tree[v].sum[1][z] += arr[tl - 1] * (z - pos);
        }
    } else {
        int tm = (tl + tr) / 2;
        build(arr, tree, v * 2, tl, tm);
        build(arr, tree, v * 2 + 1, tm + 1, tr);
        for (int z = 2; z <= 6; ++z) {
            tree[v].sum[0][z] = tree[v * 2].sum[0][z] + tree[v * 2 + 1].sum[0][z];
            tree[v].sum[1][z] = tree[v * 2].sum[1][z] + tree[v * 2 + 1].sum[1][z];
        }
    }
}

void update(vector<Node> &tree, int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        for (int z = 2; z <= 6; ++z) {
            int p = (tl - 1) % z;
            tree[v].sum[0][z] = new_val * (p + 1);
            tree[v].sum[1][z] = new_val * (z - p);
        }
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(tree, v * 2, tl, tm, pos, new_val);
        else
            update(tree, v * 2 + 1, tm + 1, tr, pos, new_val);
        for (int z = 2; z <= 6; ++z) {
            tree[v].sum[0][z] = tree[v * 2].sum[0][z] + tree[v * 2 + 1].sum[0][z];
            tree[v].sum[1][z] = tree[v * 2].sum[1][z] + tree[v * 2 + 1].sum[1][z];
        }
    }
}

long long query(const vector<Node> &tree, int v, int tl, int tr, int l, int r, int z) {
    if (l > r) return 0;
    if (l == tl && r == tr) {
        int left_pos = (tl - 1) % z;
        int right_pos = (tr - 1) % z;
        return tree[v].sum[0][z] - (left_pos == 0 ? 0 : tree[v].sum[0][z] - tree[v].sum[0][z] * (tl - 1) / z * z - tree[v].sum[0][z] / z * (left_pos)) +
               tree[v].sum[1][z] - (right_pos == z - 1 ? 0 : tree[v].sum[1][z] - tree[v].sum[1][z] * (tr - 1) / z * z - tree[v].sum[1][z] / z * (z - right_pos - 1));
    }
    int tm = (tl + tr) / 2;
    long long left_query = query(tree, v * 2, tl, tm, l, min(r, tm), z);
    long long right_query = query(tree, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, z);
    return left_query + right_query;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    vector<Node> tree(4 * n);
    build(a, tree, 1, 0, n - 1);
    int m;
    cin >> m;
    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int p, v;
            cin >> p >> v;
            --p;
            update(tree, 1, 0, n - 1, p, v);
        } else {
            int l, r, z;
            cin >> l >> r >> z;
            --l;
            --r;
            cout << query(tree, 1, 0, n - 1, l, r, z) << '\n';
        }
    }
    return 0;
}