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
int arr[200005], tree[4 * 200005], lazy[4 * 200005];
struct info {
  int l, r, i;
};
vector<info> vec;
bool comp(info a, info b) {
  if (a.r != b.r) return a.r < b.r;
  return a.l < b.l;
}
void update(int node, int a, int b, int i, int j, int value) {
  if (lazy[node] != 0) {
    tree[node] += lazy[node];
    if (a != b) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
  if (a > b || a > j || b < i) return;
  if (a >= i && b <= j) {
    tree[node] += value;
    if (a != b) {
      lazy[node * 2] += value;
      lazy[node * 2 + 1] += value;
    }
    return;
  }
  int mid = (a + b) / 2;
  update(node * 2, a, mid, i, j, value);
  update(1 + node * 2, 1 + mid, b, i, j, value);
  tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}
int query(int node, int a, int b, int i, int j) {
  if (a > b || a > j || b < i) return 0;
  if (lazy[node] != 0) {
    tree[node] += lazy[node];
    if (a != b) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
  if (a >= i && b <= j) return tree[node];
  int mid = (a + b) / 2;
  int q1 = query(node * 2, a, mid, i, j);
  int q2 = query(1 + node * 2, 1 + mid, b, i, j);
  int res = max(q1, q2);
  return res;
}
int main() {
  int i, n, k, a, b, mx = -1;
  scanf("%d %d", &n, &k);
  for (i = 0; i < n; i++) {
    scanf("%d %d", &a, &b);
    mx = max(mx, b);
    vec.push_back({a, b, i + 1});
  }
  sort((vec).begin(), (vec).end(), comp);
  queue<int> q;
  for (i = 0; i < n; i++) {
    int l = vec[i].l, r = vec[i].r;
    int mxv = query(1, 0, mx - 1, l - 1, r - 1);
    if (mxv < k)
      update(1, 0, mx - 1, l - 1, r - 1, 1);
    else
      q.push(vec[i].i);
  }
  printf("%d\n", q.size());
  while (!q.empty()) {
    printf("%d ", q.front());
    q.pop();
  }
}