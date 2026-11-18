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
bool sortin(const pair<long long int, long long int> &e,
            const pair<long long int, long long int> &f) {
  return (e.first < f.first);
}
long long int i, j, k, l, m, n, c, p, q;
long long int a[250002], b[100002], x[100002];
int main() {
  {
    ((void)0);
    ((void)0);
    ((void)0);
  };
  cin >> q;
  while (q--) {
    map<long long int, long long int> mp, np;
    cin >> n;
    cin >> m;
    cin >> l;
    for (int i = 0; i <= n - 1; i++) cin >> a[i];
    for (int i = 0; i <= l - 1; i++) mp[a[i]]++;
    c = mp.size();
    for (int i = l; i <= n - 1; i++) {
      mp[a[i - l]]--;
      if (mp[a[i - l]] == 0) mp.erase(a[i - l]);
      mp[a[i]]++;
      k = mp.size();
      c = min(c, k);
    }
    cout << c;
    cout << endl;
  }
}