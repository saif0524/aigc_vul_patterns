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
#define N 1005
#define M 1001
#define P 30
using namespace std;
typedef long long ll;

int main(){
  int v,d;
  ll f[N];
  vector<ll> F;
  while(cin>>v>>d){
    f[0]=f[1]=1;
    for(int i=2;i<2+v;i++){
      f[i]=(f[i-1]+f[i-2])%M;
      F.push_back(f[i]);
    }
    sort(F.begin(),F.end());
    int ans=0;
    for(int i=1;i<F.size();i++){
      if(abs(F[i]-F[i-1])>=d)ans++;
    }
    cout<<ans+1<<endl;
    F.clear();
  }
  return 0;
}