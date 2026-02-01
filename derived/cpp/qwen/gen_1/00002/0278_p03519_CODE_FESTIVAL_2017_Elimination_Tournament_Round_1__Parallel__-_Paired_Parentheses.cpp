#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node {
    ll open_match, close_match, open_plus, close_plus;
    Node() : open_match(0), close_match(0), open_plus(0), close_plus(0) {}
};

Node merge(Node l, Node r) {
    Node res;
    res.open_plus = l.open_plus + r.open_plus + l.open_match - min(l.open_match, r.close_plus);
    res.close_plus = l.close_plus + r.close_plus + r.close_match - min(r.close_match, l.open_plus);
    res.open_match = l.open_match + r.open_match + min(l.open_plus, r.close_plus);
    res.close_match = l.close_match + r.close_match + min(r.open_plus, l.close_plus);
    return res;
}

void pull(vector<Node> &tree, int v) {
    tree[v] = merge(tree[2*v], tree[2*v+1]);
}

void build(vector<Node> &tree, int v, int tl, int tr, vector<pair<ll, ll>> &a) {
    if (tl == tr) {
        tree[v].open_plus = a[tl].second;
        tree[v].close_plus = -a[tl].second;
        tree[v].open_match = tree[v].close_match = a[tl].first;
        return;
    }
    int tm = (tl + tr) / 2;
    build(tree, 2*v, tl, tm, a);
    build(tree, 2*v+1, tm+1, tr, a);
    pull(tree, v);
}

void update(vector<Node> &tree, int v, int tl, int tr, int pos, ll x, ll y) {
    if (tl == tr) {
        tree[v].open_plus = y;
        tree[v].close_plus = -y;
        tree[v].open_match = tree[v].close_match = x;
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
        update(tree, 2*v, tl, tm, pos, x, y);
    } else {
        update(tree, 2*v+1, tm+1, tr, pos, x, y);
    }
    pull(tree, v);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    int sz = 2 * N;
    vector<pair<ll, ll>> a(sz);
    for(int i=0;i<sz;i++)cin>>a[i].first;
    for(int i=0;i<sz;i++)cin>>a[i].second;
    vector<Node> tree(4*sz);
    build(tree, 1, 0, sz-1, a);
    while(Q--){
        int p;
        ll x, y;
        cin >> p >> x >> y;
        --p;
        update(tree, 1, 0, sz-1, p, x, y);
        cout << tree[1].open_match+tree[1].close_match+tree[1].open_plus+tree[1].close_plus << "\n";
    }
}