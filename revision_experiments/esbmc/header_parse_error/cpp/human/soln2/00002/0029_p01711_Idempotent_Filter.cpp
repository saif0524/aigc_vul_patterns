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

int buff[][7] = {
  {0, 1, 2, 4, 6, 7, 9},
  {1, 3, 4, 6, 8, 9, 11},
  {2, 4, 5, 7, 9, 10, 12},
  {4, 6, 7, 9, 11, 12, 14},
  {6, 8, 9, 11, 13, 14, 16},
  {7, 9, 10, 12, 14, 15, 17},
  {9, 11, 12, 14, 16, 17, 18}
};
int main()
{
  string S;
  int arr[7];
  
  while(cin >> S, S != "#") {
    bool f = true;
    for(int i = (1 << 19) - 1; i >= 0; i--) {
      int sum = 0;
      for(int j = 0; j < 7; j++) {
        arr[j] = 0;
        for(int k = 0; k < 7; k++) arr[j] += ((i >> buff[j][k]) & 1) << k;
        sum += (S[arr[j]] - '0') << j;
      }
      if(S[sum] != S[arr[3]]) {
        f = false;
        break;
      }
    }
    cout << (f ? "yes" : "no") << endl;
  }
}