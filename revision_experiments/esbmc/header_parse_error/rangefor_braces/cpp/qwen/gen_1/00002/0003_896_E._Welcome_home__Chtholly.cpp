// [esbmc] replaced #include <bits/stdc++.h> with ESBMC-compatible headers
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <istream>
#include <ostream>
#include <ios>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <streambuf>
#include <string>
#include <string_view>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <iterator>
#include <memory>
#include <tuple>
#include <limits>
#include <random>
#include <complex>
#include <valarray>
#include <stdexcept>
#include <exception>
#include <typeinfo>
#include <type_traits>
#include <initializer_list>
#include <numbers>
#include <any>
using namespace std;

struct Node {
    int l, r, s, v;
};

const int MAXN = 1e5 + 5;
int n, m;
vector<Node> seg;
vector<int> a;

void build(int id, int l, int r) {
    seg[id] = {l, r, r - l + 1, 0};
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
}

void push_down(int id) {
    if (seg[id].v == 0) return;
    int mid = (seg[id].l + seg[id].r) >> 1;
    seg[id << 1].v += seg[id].v;
    seg[id << 1].s -= max(0, min(seg[id << 1].r - seg[id << 1].l + 1, seg[id << 1].v));
    seg[id << 1 | 1].v += seg[id].v;
    seg[id << 1 | 1].s -= max(0, min(seg[id << 1 | 1].r - seg[id << 1 | 1].l + 1, seg[id << 1 | 1].v));
    seg[id].v = 0;
}

void update(int id, int l, int r, int x) {
    if (seg[id].l >= l && seg[id].r <= r) {
        seg[id].s -= max(0, min(seg[id].r - seg[id].l + 1, x));
        seg[id].v += x;
        return;
    }
    push_down(id);
    int mid = (seg[id].l + seg[id].r) >> 1;
    if (l <= mid) update(id << 1, l, r, x);
    if (r > mid) update(id << 1 | 1, l, r, x);
}

int query(int id, int l, int r, int x) {
    if (seg[id].l >= l && seg[id].r <= r) {
        return seg[id].s - max(0, seg[id].s - max(0, seg[id].r - seg[id].l + 1 - x));
    }
    push_down(id);
    int mid = (seg[id].l + seg[id].r) >> 1;
    int ans = 0;
    if (l <= mid) ans += query(id << 1, l, r, x);
    if (r > mid) ans += query(id << 1 | 1, l, r, x);
    return ans;
}

int main() {
    ((void)0);
    ((void)0);
    cin >> n >> m;
    a.resize(n);
    for (int &x : a) { cin >> x; }
    seg.resize(n * 4);
    build(1, 0, n - 1);
    while (m--) {
        int op, l, r, x;
        cin >> op >> l >> r >> x;
        l--, r--;
        if (op == 1) update(1, l, r, x);
        else cout << query(1, l, r, x) << "\n";
    }
    return 0;
}