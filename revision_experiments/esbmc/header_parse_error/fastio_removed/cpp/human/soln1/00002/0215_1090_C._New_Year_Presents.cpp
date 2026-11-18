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
const int maxn = 100005;
pair<int, int> qq[maxn];
int q[maxn], s, o[maxn];
set<int> w[maxn], z;
vector<pair<pair<int, int>, int> > r;
int main() {
  int n, m, a, b, qa, qb;
  ((void)0);
  ((void)0);
  ((void)0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> q[i];
    s += q[i];
    qq[i] = make_pair(q[i], i);
    for (int j = 0; j < q[i]; j++) {
      int t;
      cin >> t;
      t--;
      w[t].insert(i);
    }
  }
  a = s / n;
  b = a + 1;
  qb = s % n;
  qa = n - qb;
  sort(qq, qq + n);
  for (int i = 0; i < qa; i++) o[qq[i].second] = a;
  for (int i = qa; i < n; i++) o[qq[i].second] = b;
  for (int i = 0; i < n; i++)
    if (q[i] < o[i]) z.insert(i);
  for (int i = 0; i < m; i++) {
    int k = 0;
    for (int t : w[i]) {
      if (q[t] > o[t]) {
        bool flag = false;
        while (1) {
          auto it = z.lower_bound(k);
          if (it == z.end()) {
            flag = true;
            break;
          }
          k = *it;
          assert(q[k] < o[k]);
          if (w[i].count(k)) {
            k++;
            continue;
          }
          r.push_back(make_pair(make_pair(t, k), i));
          q[t]--;
          q[k]++;
          if (q[k] == o[k]) z.erase(k);
          k++;
          break;
        }
        if (flag) break;
      }
    }
  }
  cout << r.size() << endl;
  for (int i = 0; i < r.size(); i++) {
    cout << r[i].first.first + 1 << " " << r[i].first.second + 1 << " "
         << r[i].second + 1 << endl;
  }
}