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
const long long INF = 1e9;
int main() {
  long long n, k;
  cin >> n >> k;
  set<long long> s;
  long long a[1000001] = {};
  for (long long i = 0; i < n; i++) {
    long long temp;
    cin >> temp;
    s.insert(temp);
    a[temp]++;
  }
  set<long long>::iterator itr;
  vector<long long> v;
  for (itr = s.begin(); itr != s.end(); itr++) v.push_back(*itr);
  sort(v.begin(), v.end());
  long long ans = n;
  for (long long i = 0; i < v.size(); i++) {
    if (v[i] < v[i + 1] && v[i] + k >= v[i + 1]) ans -= a[v[i]];
  }
  cout << ans;
  return 0;
}