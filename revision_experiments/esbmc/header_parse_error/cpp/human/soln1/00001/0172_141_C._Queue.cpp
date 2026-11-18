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
  int n, nop, i, j, k, l, a, temp;
  char b[100];
  string stt[3010];
  vector<pair<int, string> > vct;
  vector<int> v2, v3;
  cin >> n;
  nop = n;
  for (i = 0; i < n; i++) {
    cin >> stt[i] >> a;
    vct.push_back(make_pair(a, stt[i]));
    v2.push_back(i);
  }
  v2.push_back(n);
  sort(vct.begin(), vct.end());
  for (i = 0; i < n; i++) {
    if (vct[i].first > i) {
      cout << -1 << endl;
      return 0;
    }
  }
  int nn = n;
  for (i = nn - 1; i >= 0; i--) {
    if (vct[i].first != 0) {
      temp = v2[n - vct[i].first];
      v3.push_back(temp);
      v2.erase(v2.begin() + n - vct[i].first);
      n--;
    }
  }
  if (v2.empty() == 0) {
    nn = v2.size();
    for (i = nn - 1; i > 0; i--) v3.push_back(v2[i]);
  }
  for (i = nop - 1, j = 0; i >= 0; j++, i--) {
    cout << vct[nop - i - 1].second << " " << v3[i] << endl;
  }
  return 0;
}