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
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
int n, m;
int a[N];
int fib[N];
int tree[4 * N];

void build(int node, int start, int end) {
  if (start == end) {
    tree[node] = a[start];
  } else {
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }
}

void update(int node, int start, int end, int l, int r, int val) {
  if (start > r || end < l) return;
  if (start == end) {
    tree[node] += val;
  } else {
    int mid = (start + end) / 2;
    update(2 * node, start, mid, l, r, val);
    update(2 * node + 1, mid + 1, end, l, r, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }
}

int query(int node, int start, int end, int l, int r) {
  if (start > r || end < l) return 0;
  if (l <= start && end <= r) return tree[node];
  int mid = (start + end) / 2;
  return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
}

int main() {
  fib[1] = 1;
  fib[2] = 1;
  for (int i = 3; i < N; i++) {
    fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
  }
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, 1, n);
  while (m--) {
    int type;
    cin >> type;
    if (type == 1) {
      int l, r, val;
      cin >> l >> r >> val;
      update(1, 1, n, l, r, val);
    } else {
      int l, r;
      cin >> l >> r;
      int sum = 0;
      for (int i = l; i <= r; i++) {
        sum = (sum + fib[query(1, 1, n, i, i)]) % mod;
      }
      cout << sum << endl;
    }
  }
  return 0;
}