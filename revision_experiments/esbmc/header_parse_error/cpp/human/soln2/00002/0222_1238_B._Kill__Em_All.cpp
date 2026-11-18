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
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  srand(time(NULL));
  ;
  int n, r, q, i, j;
  cin >> q;
  while (q) {
    cin >> n >> r;
    set<int> s;
    int c = 0;
    for (i = 0; i < n; i++) {
      cin >> j;
      s.insert(j);
    }
    vector<int> v;
    for (auto it = s.begin(); it != s.end(); it++) {
      j = *it;
      v.push_back(j);
    }
    n = v.size();
    reverse(v.begin(), v.end());
    for (i = 0; i < n; i++) {
      if ((v[i] - (r * c)) <= 0) {
        break;
      }
      c++;
    }
    cout << i << endl;
    q--;
  }
  return 0;
}