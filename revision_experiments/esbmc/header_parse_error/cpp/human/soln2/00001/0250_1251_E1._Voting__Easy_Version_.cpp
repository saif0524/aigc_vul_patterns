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
struct node {
  long long m, p;
  friend bool operator<(node a, node b) { return a.p < b.p; }
};
bool cmp(node a, node b) { return a.m < b.m; }
int main() {
  ios::sync_with_stdio(false);
  long long T;
  cin >> T;
  for (long long w = 0; w < T; w++) {
    long long n;
    cin >> n;
    node per[n];
    for (long long i = 0; i < n; i++) {
      cin >> per[i].m >> per[i].p;
    }
    sort(per, per + n, cmp);
    priority_queue<node> q;
    long long t = 0;
    for (long long i = 0; i < n; i++) {
      while (1) {
        if (per[t].m == i) {
          q.push(per[t]);
          t++;
        } else {
          break;
        }
      }
      if (q.empty()) {
        continue;
      } else {
        q.pop();
      }
    }
    long long ans = 0;
    while (!q.empty()) {
      node xx = q.top();
      q.pop();
      ans += xx.p;
    }
    cout << ans << endl;
  }
  return 0;
}