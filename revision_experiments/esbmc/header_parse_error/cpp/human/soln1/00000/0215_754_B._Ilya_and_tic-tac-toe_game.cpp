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
char board[4][4];
bool Valid(int x, int y) { return (x >= 0 && x < 4 && y >= 0 && y < 4); }
int main() {
  std::ios::sync_with_stdio(false);
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      cin >> board[i][j];
    }
  }
  bool valid = false;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (board[i][j] == 'x') {
        if (Valid(i - 1, j) && board[i - 1][j] == 'x' && Valid(i - 2, j) &&
                board[i - 2][j] == '.' ||
            Valid(i - 1, j) && board[i - 1][j] == '.' && Valid(i - 2, j) &&
                board[i - 2][j] == 'x') {
          valid = true;
          break;
        } else if (Valid(i + 1, j) && board[i + 1][j] == 'x' &&
                       Valid(i + 2, j) && board[i + 2][j] == '.' ||
                   Valid(i + 1, j) && board[i + 1][j] == '.' &&
                       Valid(i + 2, j) && board[i + 2][j] == 'x') {
          valid = true;
          break;
        } else if (Valid(i, j - 1) && board[i][j - 1] == 'x' &&
                       Valid(i, j - 2) && board[i][j - 2] == '.' ||
                   Valid(i, j - 1) && board[i][j - 1] == '.' &&
                       Valid(i, j - 2) && board[i][j - 2] == 'x') {
          valid = true;
          break;
        } else if (Valid(i, j + 1) && board[i][j + 1] == 'x' &&
                       Valid(i, j + 2) && board[i][j + 2] == '.' ||
                   Valid(i, j + 1) && board[i][j + 1] == '.' &&
                       Valid(i, j + 2) && board[i][j + 2] == 'x') {
          valid = true;
          break;
        } else if (Valid(i + 1, j + 1) && board[i + 1][j + 1] == 'x' &&
                       Valid(i + 2, j + 2) && board[i + 2][j + 2] == '.' ||
                   Valid(i + 1, j + 1) && board[i + 1][j + 1] == '.' &&
                       Valid(i + 2, j + 2) && board[i + 2][j + 2] == 'x') {
          valid = true;
          break;
        } else if (Valid(i - 1, j - 1) && board[i - 1][j - 1] == 'x' &&
                       Valid(i - 2, j - 2) && board[i - 2][j - 2] == '.' ||
                   Valid(i - 1, j - 1) && board[i - 1][j - 1] == '.' &&
                       Valid(i - 2, j - 2) && board[i - 2][j - 2] == 'x') {
          valid = true;
          break;
        } else if (Valid(i - 1, j + 1) && board[i - 1][j + 1] == 'x' &&
                       Valid(i - 2, j + 2) && board[i - 2][j + 2] == '.' ||
                   Valid(i - 1, j + 1) && board[i - 1][j + 1] == '.' &&
                       Valid(i - 2, j + 2) && board[i - 2][j + 2] == 'x') {
          valid = true;
          break;
        } else if (Valid(i + 1, j - 1) && board[i + 1][j - 1] == 'x' &&
                       Valid(i + 2, j - 2) && board[i + 2][j - 2] == '.' ||
                   Valid(i + 1, j - 1) && board[i + 1][j - 1] == '.' &&
                       Valid(i + 2, j - 2) && board[i + 2][j - 2] == 'x') {
          valid = true;
          break;
        }
      }
    }
  }
  (valid) ? cout << "YES\n" : cout << "NO\n";
  return 0;
}