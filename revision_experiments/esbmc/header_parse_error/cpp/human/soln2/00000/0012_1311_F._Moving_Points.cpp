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
  int n;
  cin >> n;
  int arr[n];
  int v[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) cin >> v[i];
  map<int, int> mp;
  vector<pair<int, int> > vi;
  vector<pair<int, int> > vf;
  for (int i = 0; i < n; i++) {
    vi.push_back({arr[i], v[i]});
    vf.push_back({v[i], arr[i]});
  }
  sort(vi.begin(), vi.end());
  sort(vf.begin(), vf.end());
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int val = vi[i].first;
    mp[val] = i;
    ans += (2 * i - n + 1) * ((long long)val);
  }
  for (int i = 0; i < n; i++) {
    int val = vf[i].second;
    if (mp[val] == i) continue;
    ans += (i - mp[val]) * (long long)val;
  }
  cout << ans << endl;
}