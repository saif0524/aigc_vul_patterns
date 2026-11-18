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

const int N = 1e5 + 10, MOD = 1e9 + 7;

struct Node {
    long long val;
    int l, r, lazy;
};

Node tree[N << 2];
int arr[N], n, m;

void pushUp(int k) {
    tree[k].val = tree[k << 1].val + tree[k << 1 | 1].val;
}

void pushDown(int k) {
    if (tree[k].lazy) {
        tree[k << 1].val += (tree[k << 1].r - tree[k << 1].l + 1) * tree[k].lazy;
        tree[k << 1 | 1].val += (tree[k << 1 | 1].r - tree[k << 1 | 1].l + 1) * tree[k].lazy;
        tree[k << 1].lazy += tree[k].lazy;
        tree[k << 1 | 1].lazy += tree[k].lazy;
        tree[k].lazy = 0;
    }
}

void build(int k, int l, int r) {
    tree[k].l = l;
    tree[k].r = r;
    tree[k].lazy = 0;
    if (l == r) {
        tree[k].val = arr[l];
        return;
    }
    int mid = l + r >> 1;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
    pushUp(k);
}

void update(int k, int l, int r, int x) {
    if (l <= tree[k].l && tree[k].r <= r) {
        tree[k].val += (tree[k].r - tree[k].l + 1) * x;
        tree[k].lazy += x;
        return;
    }
    pushDown(k);
    int mid = tree[k].l + tree[k].r >> 1;
    if (l <= mid) {
        update(k << 1, l, r, x);
    }
    if (r > mid) {
        update(k << 1 | 1, l, r, x);
    }
    pushUp(k);
}

long long query(int k, int l, int r) {
    if (l <= tree[k].l && tree[k].r <= r) {
        return tree[k].val;
    }
    pushDown(k);
    int mid = tree[k].l + tree[k].r >> 1;
    long long res = 0;
    if (l <= mid) {
        res += query(k << 1, l, r);
    }
    if (r > mid) {
        res += query(k << 1 | 1, l, r);
    }
    return res;
}

long long fib(long long x) {
    if (x <= 1) {
        return 1;
    }
    long long a = 1, b = 1, c = 0;
    for (int i = 3; i <= x; i++) {
        c = (a + b) % MOD;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    ((void)0);
    ((void)0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    build(1, 1, n);
    while (m--) {
        int op, l, r, x;
        cin >> op >> l >> r;
        if (op == 1) {
            cin >> x;
            update(1, l, r, x);
        } else {
            long long ans = 0;
            for (int i = l; i <= r; i++) {
                ans = (ans + fib(query(1, i, i))) % MOD;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}