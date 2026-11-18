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
const long double eps = 1e-12;
const int maxn = 100000 + 1912;
const int MX = 1e6;
int n;
pair<int, int> a[maxn];
vector<int> p[MX * 2 + 3];
long long res = 0;
void ReadData() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i].first, &a[i].second);
    a[i].first += MX;
    a[i].second += MX;
    p[a[i].first].push_back(a[i].second);
  }
  for (int i = 0; i <= MX * 2; i++)
    if (((int)p[i].size())) sort(p[i].begin(), p[i].end());
}
bool Found(int x, int y) {
  if (x < 0 || x > MX * 2) return false;
  vector<int>::iterator it = lower_bound(p[x].begin(), p[x].end(), y);
  if (it != p[x].end() && (*it) == y) return true;
  return false;
}
void Process() {
  for (int i = 0; i <= MX * 2; i++)
    if (((int)p[i].size())) {
      if (((int)p[i].size()) <= 520) {
        for (int fi = 0; fi < ((int)p[i].size()); fi++)
          for (int se = 0; se < fi; se++) {
            int len = p[i][fi] - p[i][se];
            if (i >= len && Found(i - len, p[i][se]) &&
                Found(i - len, p[i][fi]))
              res++;
          }
      } else {
        for (int j = 0; j <= i - 1; j++) {
          int len = i - j;
          for (int k = 0; k < ((int)p[j].size()); k++) {
            if (Found(i, p[j][k]) && Found(j, p[j][k] + len) &&
                Found(i, p[j][k] + len))
              res++;
          }
        }
      }
    }
  cout << res << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ReadData();
  Process();
}