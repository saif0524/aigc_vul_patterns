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
    string s1, s2;
    cin >> s1 >> s2;
    if (s1 < s2) {
      cout << s1 << endl;
      continue;
    }
    bool flag = false;
    for (int i = 0; i < s1.size(); i++) {
      if (flag) break;
      for (int j = i; j < s1.size(); j++) {
        if (j == i) continue;
        if (s1[i] > s1[j]) {
          swap(s1[i], s1[j]);
          if (s1 < s2) {
            flag = true;
            break;
          } else
            swap(s1[i], s1[j]);
        }
      }
    }
    if (!flag)
      cout << "---" << endl;
    else
      cout << s1 << endl;
  }
}