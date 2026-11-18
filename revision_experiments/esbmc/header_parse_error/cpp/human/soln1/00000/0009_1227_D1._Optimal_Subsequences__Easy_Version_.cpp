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
int main(int argc, const char* argv[]) {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  vector<int> v2 = v;
  sort(v.rbegin(), v.rend());
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int k, ind;
    cin >> k >> ind;
    multiset<int> kmax;
    for (int i = 0; i < k; ++i) {
      kmax.insert(v[i]);
    }
    vector<int> seq;
    for (int i = 0; i < n; ++i) {
      auto it = kmax.find(v2[i]);
      if (it != kmax.end()) {
        kmax.erase(it);
        seq.push_back(v2[i]);
      }
      if (seq.size() == k) {
        break;
      }
    }
    cout << seq[ind - 1] << "\n";
  }
  return 0;
}