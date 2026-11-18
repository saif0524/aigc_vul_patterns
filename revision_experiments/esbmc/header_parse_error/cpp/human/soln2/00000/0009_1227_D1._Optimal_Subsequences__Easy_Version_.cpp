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
vector<int> s[110][110], answer[110];
long long dp[110][110];
long long val[110];
int arr[110];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[i][j] = arr[j];
      s[i][j].push_back(arr[j]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      for (int k = 1; k <= j - 1; ++k) {
        if (dp[i - 1][k] + arr[j] > dp[i][j]) {
          dp[i][j] = dp[i - 1][k] + arr[j];
          s[i][j] = s[i - 1][k];
          s[i][j].push_back(arr[j]);
        } else if (dp[i - 1][k] + arr[j] == dp[i][j]) {
          for (int l = 0; l < s[i - 1][k].size(); ++l) {
            if (s[i - 1][k][l] < s[i][j][l]) {
              s[i][j] = s[i - 1][k];
              s[i][j].push_back(arr[j]);
              break;
            } else if (s[i - 1][k][l] > s[i][j][l]) {
              break;
            }
          }
        }
      }
      if (dp[i][j] > val[i]) {
        val[i] = dp[i][j];
        answer[i] = s[i][j];
      } else if (dp[i][j] == val[i]) {
        for (int l = 0; l < s[i][j].size(); ++l) {
          if (s[i][j][l] < answer[i][l]) {
            answer[i] = s[i][j];
            break;
          } else if (s[i][j][l] > answer[i][l]) {
            break;
          }
        }
      }
    }
  }
  int q;
  cin >> q;
  while (--q > -1) {
    int k, pos;
    cin >> k >> pos;
    cout << answer[k][pos - 1] << '\n';
  }
}