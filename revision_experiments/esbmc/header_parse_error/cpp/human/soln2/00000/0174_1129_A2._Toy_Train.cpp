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
int n;
int m;
vector<int> v[5002];
int w[5002];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) w[i] = INT_MAX;
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    v[a].push_back(b);
    w[a] = min(w[a], (b + n - a) % n);
  }
  for (int i = 0; i < n; i++) {
    int cap = 0;
    for (int j = 0; j < n; j++) {
      cap = max(cap, (int)(v[j].size()));
    }
    int tim = n * (cap - 1);
    int maxi = 0;
    for (int j = 0; j < n; j++) {
      if (w[j] == INT_MAX) continue;
      if (v[j].size() == cap) {
        maxi = max(maxi, w[j] + (j + n - i) % n);
      } else {
        if (v[j].size() == cap - 1) {
          maxi = max(maxi, w[j] + (j + n - i) % n - n);
        }
      }
    }
    tim += maxi;
    if (i) printf(" ");
    printf("%d", tim);
  }
  puts("");
  return 0;
}