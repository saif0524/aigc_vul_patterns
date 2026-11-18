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
vector<vector<int> > v;
int main() {
  int i, j, k, n, c = 0;
  cin >> n >> k;
  for (i = 0; i < k; i++) {
    int temp;
    cin >> temp;
    vector<int> v1;
    for (j = 0; j < temp; j++) {
      int t;
      cin >> t;
      v1.push_back(t);
    }
    if (v1.size() > 1) {
      vector<int> v2;
      v2.push_back(v1[0]);
      int ii;
      for (ii = 0; ii < v1.size() - 1;) {
        if (v1[ii] == v1[ii + 1] - 1) {
          v2.push_back(v1[ii + 1]);
          ii++;
        } else {
          c++;
          v.push_back(v2);
          v2.clear();
          c += v1.size() - ii - 2;
          for (int kk = ii + 1; kk < v1.size(); kk++) {
            v2.clear();
            v2.push_back(v1[kk]);
            v.push_back(v2);
            v2.clear();
          }
          break;
        }
      }
      if (v2.size() > 0) v.push_back(v2);
    } else
      v.push_back(v1);
  }
  sort(v.begin(), v.end());
  int sum = c;
  for (i = 0; i < v.size() - 1; i++) {
    if (v[i + 1].size() > 1) {
      int temp = v[i + 1].size() - 1;
      sum += temp;
      sum++;
      sum += temp;
    } else
      sum++;
  }
  cout << sum << "\n";
  return 0;
}