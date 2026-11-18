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
  string s1, s2;
  cin >> s1 >> s2;
  set<char> ns;
  char arr[s1.length()];
  for (long int i = 0; i < s1.length(); i++) {
    arr[i] = s1[i];
    ns.insert(s1[i]);
  }
  if (ns.size() == 1 && s1[0] == '0') {
    if (s2 == "0")
      cout << "OK\n";
    else
      cout << "WRONG_ANSWER\n";
  } else {
    long int pos;
    for (pos = 0; arr[pos] == '0'; pos++)
      ;
    for (long int i = 0; i < s1.length(); i++) {
      if (arr[i] != '0' && arr[i] < arr[pos]) pos = i;
    }
    swap(arr[pos], arr[0]);
    sort(arr + 1, arr + s1.length());
    if (arr[0] != '0' && s1.length() == s2.length()) {
      bool check = 0;
      for (long int i = 0; i < s1.length(); i++) {
        if (arr[i] != s2[i]) {
          check = 1;
          break;
        }
      }
      if (check == 1)
        cout << "WRONG_ANSWER\n";
      else
        cout << "OK\n";
    } else
      cout << "WRONG_ANSWER\n";
  }
  return 0;
}