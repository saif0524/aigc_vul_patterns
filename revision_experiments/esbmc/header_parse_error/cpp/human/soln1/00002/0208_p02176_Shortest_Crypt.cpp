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
using int64 = long long;
#define int int64
#define debug(x) cerr<<#x<<":"<<(x)<<endl;

signed main() {
  int n;cin>>n;
  string s; cin>>s;
  int x=0,y=0;
  for(int i=0;i<s.size();++i){
    if ('a' <= s[i] && s[i] <= 'm') ++x;
    if ('n' <= s[i] && s[i] <= 'z') --x;
    if ('A' <= s[i] && s[i] <= 'M') ++y;
    if ('N' <= s[i] && s[i] <= 'Z') --y;
  }

  string ans = "";
  
  if (x<0) ans += string(abs(x),'n');
  else if(x>0) ans += string(x, 'a');
  if (y<0) ans += string(abs(y),'N');
  else if(y>0) ans += string(y, 'A');
  
  cout<<ans.size()<<endl;
  cout<<ans<<endl;
  return 0;
}