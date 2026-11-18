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
int main(){
  ll n,k;
  cin>>n>>k;
  vector<ll> a(n),b(n+1,0),c(n+1,0);
  for(ll i=0;i<n;i++) cin>>a[i];
  for(ll i=0;i<n;i++){
    b[i+1]=b[i]+(a[i]>0?a[i]:0);
    c[i+1]=c[i]+a[i];
  }
  ll ans=0,tmp=0;
  for(int i=0;i<=n-k;i++){
    tmp=b[n]-b[i+k]+b[i];
    ans=max(ans,tmp);
    tmp+=c[i+k]-c[i];
    ans=max(ans,tmp);
  }
  cout<<ans<<endl;
  return 0;
}