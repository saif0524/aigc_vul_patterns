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
const int N = 400000;
int a[N], t[N], type[N], us[N];
int main() {
  ((void)0);
  int n, w, k;
  cin >> n >> w >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  int r = -1;
  int curr_time = 0;
  int earn = 0;
  set<pair<int, int> > half, full;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    r = max(r, i - 1);
    while (r < n - 1) {
      r++;
      int temp = curr_time;
      vector<pair<int, int> > pers_full, pers_half, pers_type;
      half.insert(make_pair(t[r], r));
      pers_half.push_back(make_pair(+1, r));
      pers_type.push_back(make_pair(r, type[r]));
      type[r] = 0;
      curr_time += (t[r] + 1) / 2;
      if (half.size() > w) {
        auto p = *half.begin();
        curr_time -= (p.first + 1) / 2;
        half.erase(half.find(p));
        pers_half.push_back(make_pair(-1, p.second));
        curr_time += p.first;
        full.insert(p);
        pers_full.push_back(make_pair(+1, p.second));
        pers_type.push_back(make_pair(p.second, type[p.second]));
        type[p.second] = 1;
      }
      if (curr_time > k) {
        while (pers_full.size()) {
          auto p = pers_full.back();
          pers_full.pop_back();
          if (p.first == -1)
            full.insert(make_pair(t[p.second], p.second));
          else
            full.erase(make_pair(t[p.second], p.second));
        }
        while (pers_half.size()) {
          auto p = pers_half.back();
          pers_half.pop_back();
          if (p.first == -1)
            half.insert(make_pair(t[p.second], p.second));
          else
            half.erase(make_pair(t[p.second], p.second));
        }
        while (pers_type.size()) {
          auto p = pers_type.back();
          pers_type.pop_back();
          type[p.first] = p.second;
        }
        curr_time = temp;
        r--;
        break;
      } else {
        earn += a[r];
        us[r] = 1;
      }
    }
    ans = max(earn, ans);
    if (us[i] == 1) {
      if (type[i] == 0) {
        half.erase(make_pair(t[i], i));
        curr_time -= (t[i] + 1) / 2;
      } else {
        full.erase(make_pair(t[i], i));
        curr_time -= t[i];
      }
      earn -= a[i];
      us[i] = 0;
      while (full.size() && half.size() < w) {
        auto p = *full.rbegin();
        full.erase(full.find(p));
        half.insert(p);
        curr_time -= p.first;
        curr_time += (p.first + 1) / 2;
        type[p.second] = 0;
      }
    }
  }
  cout << ans << "\n";
  return 0;
}