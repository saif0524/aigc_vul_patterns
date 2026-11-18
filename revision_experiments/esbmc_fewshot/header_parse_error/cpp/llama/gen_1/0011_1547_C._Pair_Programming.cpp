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

int main() {
  int t;
  cin >> t;
  while (t--) {
    int k, n, m;
    cin >> k >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    vector<int> ans;
    int i = 0, j = 0;
    while (i < n || j < m) {
      if (i < n && a[i] <= k) {
        ans.push_back(a[i]);
        if (a[i] == 0) k++;
        i++;
      } else if (j < m && b[j] <= k) {
        ans.push_back(b[j]);
        if (b[j] == 0) k++;
        j++;
      } else {
        cout << -1 << endl;
        goto next;
      }
    }
    for (int x : ans) cout << x << " ";
    cout << endl;
    next:;
  }
  return 0;
}