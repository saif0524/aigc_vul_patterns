#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

struct PersistentSegtree {
    struct Node {
        int l, r, sum;
    } nodes[N * 30];
    int root[N], tail;

    int build(int l, int r) {
        int cur = tail++;
        nodes[cur] = {l, r, 0};
        if (l == r) return cur;
        int m = (l + r) / 2;
        nodes[cur].l = build(l, m);
        nodes[cur].r = build(m + 1, r);
        return cur;
    }

    int update(int pre, int l, int r, int pos, int val) {
        int cur = tail++;
        nodes[cur] = nodes[pre];
        if (l == r) {
            nodes[cur].sum += val;
            return cur;
        }
        int m = (l + r) / 2;
        if (pos <= m) nodes[cur].l = update(nodes[pre].l, l, m, pos, val);
        else nodes[cur].r = update(nodes[pre].r, m + 1, r, pos, val);
        nodes[cur].sum = nodes[nodes[cur].l].sum + nodes[nodes[cur].r].sum;
        return cur;
    }

    int query(int roots[], int l, int r, int s, int t, int last) {
        if (s <= l && r <= t) return nodes[roots[last]].sum - nodes[roots[r]].sum;
        int m = (l + r) / 2, res = 0;
        if (s <= m) res += query(roots, l, m, s, t, last);
        if (t > m) res += query(roots, m + 1, r, s, t, t);
        return res;
    }
} pst;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    vector<vector<int>> first(n + 1, vector<int>(n, -1)), last(n + 1, vector<int>(n, -1));
    vector<int> pos(n);
    for(int i = 0; i < n; i++){
        if(first[a[i]][pos[a[i]]] == -1) first[a[i]][pos[a[i]]] = i;
        last[a[i]][pos[a[i]]] = i;
        pos[a[i]]++;
    }
    for(int i = 0; i <= n; i++) pos[i] = 0;
    pst.tail = 0;
    pst.root[0] = pst.build(1, n - 1);
    for(int i = 0; i < n; i++){
        if(last[a[i]][pos[a[i]]] == i) pst.root[i + 1] = pst.update(pst.root[i], 1, n - 1, first[a[i]][pos[a[i]]], -1);
        pst.root[i + 1] = pst.update(pst.root[i + 1], 1, n - 1, i, 1);
        pos[a[i]]++;
    }
    while(m--){
        int type;
        cin >> type;
        if(type == 1){
            int p, x;
            cin >> p >> x;
            p--;
            if(last[a[p]][pos[a[p]]] == p) pst.root[p + 1] = pst.update(pst.root[p + 1], 1, n - 1, first[a[p]][pos[a[p]]], -1);
            pst.root[p + 1] = pst.update(pst.root[p + 1], 1, n - 1, p, -1);
            pos[a[p]]++;
            first[x][pos[x]] = p;
            last[x][pos[x]] = p;
            for(int j = p + 1; j <= n; j++){
                if(last[a[j - 1]][pos[a[j - 1]]] == j - 1) pst.root[j] = pst.update(pst.root[j], 1, n - 1, first[a[j - 1]][pos[a[j - 1]]], -1);
                if(last[x][pos[x]] == j - 1) pst.root[j] = pst.update(pst.root[j], 1, n - 1, first[x][pos[x]], 1);
                pst.root[j] = pst.update(pst.root[j], 1, n - 1, j - 1, 1);
            }
            a[p] = x;
        }
        else{
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << pst.query(pst.root, 1, n - 1, l, r - 1, r) << '\n';
        }
    }
}