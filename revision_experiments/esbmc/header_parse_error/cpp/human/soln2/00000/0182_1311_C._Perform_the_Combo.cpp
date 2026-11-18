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
#pragma warning(disable : 4996)
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<char> s(n);
    vector<long long> a(26);
    vector<long long> p(m);
    for (long long i = 0; i < n; i++) cin >> s[i];
    for (long long i = 0; i < m; i++) cin >> p[i];
    p.push_back(n);
    sort(p.begin(), p.end());
    long long j = 0;
    for (long long i = 0; i < n; i++) {
      a[s[i] - 'a'] += m + 1 - j;
      if (i + 1 == p[j]) {
        while (j < m && p[j] == p[j + 1]) j++;
        j++;
      }
    }
    for (long long i = 0; i < 26; i++) {
      cout << a[i] << ' ';
    }
    cout << endl;
  }
  return 0;
}