#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

struct Node {
    int val;
    Node *l, *r;
    Node(int val) : val(val), l(nullptr), r(nullptr) {}
};

Node* build(int l, int r, int* a, int* b) {
    if (l == r) {
        return new Node(max(a[l], b[l]));
    }
    int m = (l + r) / 2;
    Node* root = new Node(0);
    root->l = build(l, m, a, b);
    root->r = build(m + 1, r, a, b);
    root->val = root->l->val + root->r->val;
    return root;
}

void update(Node* root, int l, int r, int pos, int val1, int val2) {
    if (l == r) {
        root->val = max(val1, val2);
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m) {
        update(root->l, l, m, pos, val1, val2);
    } else {
        update(root->r, m + 1, r, pos, val1, val2);
    }
    root->val = root->l->val + root->r->val;
}

int query(Node* root, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) return 0;
    if (ql <= l && r <= qr) return root->val;
    int m = (l + r) / 2;
    return query(root->l, l, m, ql, qr) + query(root->r, m + 1, r, ql, qr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    n *= 2;
    int* a = new int[n];
    int* b = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    Node* root = build(0, n - 1, a, b);

    while (q--) {
        int p, x, y;
        cin >> p >> x >> y;
        p--;
        a[p] = x;
        b[p] = y;
        update(root, 0, n - 1, p, x, y);

        int ans = 0;
        int l = 0, r = 1;
        while (r < n) {
            int cur = query(root, 0, n - 1, l, r);
            ans += cur;
            l = r;
            r = l + 1;
            while (r < n && query(root, 0, n - 1, l, r) == cur) {
                r++;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}