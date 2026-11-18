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
  vector<int> matrix[52];
  int n;
  vector<int> fila(52, 0);
  cin >> n;
  for (int i = int(0); i < int(n); i++) {
    for (int j = int(0); j < int(n); j++) {
      int num;
      cin >> num;
      matrix[i].push_back(num);
    }
  }
  for (int i = int(0); i < int(n); i++) {
    vector<int> rep(51, 0);
    for (int j = int(0); j < int(n); j++) {
      rep[matrix[i][j]]++;
    }
    int pos = 0;
    int maxi = 0;
    for (int j = int(1); j < int(n); j++) {
      if (maxi < rep[j]) {
        pos = j;
        maxi = rep[j];
      }
    }
    fila[i] = pos;
    for (int j = int(0); j < int(n); j++)
      if (matrix[i][j] == j) matrix[i][j] == 0;
  }
  int pos1 = -1, pos2;
  for (int i = int(0); i < int(n); i++) {
    for (int j = int(0); j < int(n); j++) {
      if (matrix[i][j] == n - 1) {
        if (pos1 == -1) {
          pos1 = i;
        } else {
          pos2 = i;
        }
      }
    }
  }
  for (int i = int(0); i < int(n); i++) {
    if (i == pos1) {
      pos1 = -1;
      cout << n - 1 << " ";
    } else if (pos2 == i) {
      cout << n << " ";
    } else {
      cout << fila[i] << " ";
    }
  }
}