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
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
signed main(){
  Int n,q,k,d;
  cin>>n>>q>>k>>d;
  k--;d--;
  
  const int MAX = 60;
  while(q>=MAX){
    cout<<(k&1)<<"\n";
    k/=2;
    q--;
  }

  using I = __int128;
  I N=n,Q=q,K=k,D=d;

  I X=((D+0)*(I(1)<<Q)-K+N-1)/N;
  I Y=((D+1)*(I(1)<<Q)-K+N-1)/N;

  if(X==Y){
    cout<<-1<<endl;
    return 0;
  }

  for(int i=0;i<q;i++){
    int b=int((X>>i)&1)^(k&1);
    k/=2;
    k+=(n/2)*int((X>>i)&1);
    cout<<b<<"\n";
  }
  assert(k==d);
  
  cout<<flush;
  return 0;
}