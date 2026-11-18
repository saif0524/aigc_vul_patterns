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
#pragma GCC optimize("Ofast")
using namespace std;
clock_t clk = clock();
long long int i, j;
void solve(void);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int t = 1;
  while (t--) solve();
  return 0;
}
map<string, string> m;
void solve() {
  long long int n;
  cin >> n;
  for (i = 0; i <= n - 1; ++i) {
    string s;
    cin >> s;
    if (s == "typedef") {
      string a, b;
      cin >> a >> b;
      int st = 0, en = (int)a.size() - 1;
      while (a[st] == '&' && st < (int)a.size()) ++st;
      while (a[en] == '*' && en >= 0) --en;
      string temp;
      for (j = st; j <= en; ++j) temp += a[j];
      if (temp == "void") {
        if (st <= (int)a.size() - 1 - en) {
          for (j = 1; j <= (int)a.size() - 1 - en - st; ++j) temp += '*';
          a = temp;
        } else
          a = "errtype";
        m[b] = a;
        continue;
      } else if (temp == "errtype") {
        a = temp;
        m[b] = a;
        continue;
      }
      if (m.find(temp) == m.end())
        a = "errtype";
      else {
        string t = m[temp];
        if (t == "errtype")
          a = t;
        else {
          int stn = 0, enn = (int)t.size() - 1;
          while (t[stn] == '&' && stn < (int)t.size()) ++stn;
          while (t[enn] == '*' && enn >= 0) --enn;
          if (st + stn <= (int)a.size() - 1 + (int)t.size() - 1 - enn - en) {
            long long int val =
                (int)a.size() + (int)t.size() - 2 - enn - en - st - stn;
            t = "void";
            for (j = 1; j <= val; ++j) t += '*';
          } else
            t = "errtype";
          a = t;
        }
        m[b] = a;
      }
    } else {
      string a;
      cin >> a;
      if (a == "void" || a == "errtype") {
        cout << a << '\n';
        continue;
      }
      long long int st = 0, en = (int)a.size() - 1;
      while (a[st] == '&' && st < (int)a.size()) ++st;
      while (a[en] == '*' && en >= 0) --en;
      string t;
      for (j = st; j <= en; ++j) t += a[j];
      if (m.find(t) == m.end())
        cout << "errtype\n";
      else {
        string temp = m[t];
        if (temp == "errtype") {
          cout << "errtype\n";
          continue;
        }
        long long int stn = 0, enn = (int)temp.size() - 1;
        while (temp[stn] == '&' && stn < (int)temp.size()) ++stn;
        while (temp[enn] == '*' && enn >= 0) --enn;
        if (st + stn <= (int)a.size() - 1 - en + (int)temp.size() - 1 - enn) {
          long long int val =
              (int)a.size() + (int)temp.size() - 2 - en - enn - st - stn;
          temp = "void";
          for (j = 1; j <= val; ++j) temp += '*';
        } else
          temp = "errtype";
        cout << temp << '\n';
      }
    }
  }
}