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
typedef long long ll;
const int mod=1e9+7;
int main(){
  int n,m;cin >> n >> m;
  vector<int> s(n),t(m);
  for(int i=0;i<n;i++){
    cin >> s[i];
  }
  for(int j=0;j<m;j++){
    cin >> t[j];
  }
  vector<vector<ll>> dp(n+1,vector<ll>(m+1)),sum(n+1,vector<ll>(m+1));
  dp[0][0]=1;
  sum[0][0]=1;
  for(int i=0;i<=n;i++){
    sum[i][0]=1;
  }
  for(int j=0;j<=m;j++){
    sum[0][j]=1;
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(s[i]==t[j]){
        dp[i+1][j+1]=sum[i][j];
      }
      sum[i+1][j+1]=(sum[i+1][j]+sum[i][j+1]-sum[i][j]+mod+dp[i+1][j+1])%mod;
    }
  }
  cout << sum[n][m] << endl;
}