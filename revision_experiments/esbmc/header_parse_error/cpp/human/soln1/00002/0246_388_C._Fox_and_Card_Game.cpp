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
vector<int> vec;
int main() {
  int n;
  cin >> n;
  int A = 0, B = 0;
  for (int i = 0; i < n; i++) {
    int s;
    cin >> s;
    for (int j = 0; j < s / 2; j++) {
      int x;
      cin >> x;
      A += x;
    }
    if (s % 2) {
      int x;
      cin >> x;
      vec.push_back(x);
    }
    for (int j = 0; j < s / 2; j++) {
      int x;
      cin >> x;
      B += x;
    }
  }
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  for (int i = 0; i < vec.size(); i++) {
    if (i % 2)
      B += vec[i];
    else
      A += vec[i];
  }
  cout << A << ' ' << B << endl;
}