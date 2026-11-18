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
typedef long long int ll;
typedef pair<ll,ll> mp;
ll inf =  1e9;


int main(){
 while(1){
 ll h,w;
 cin>>h>>w;
 if( h==0 && w==0 ) break;
 vector<vector<ll> > e(h+2,vector<ll>(w+2,0) );
 for(ll i=1;i<=h;i++)for(ll j=1;j<=w;j++) cin>>e[i][j];
 ll res = 0;
 for(ll l=1;l<=h;l++){
  for(ll u=l+2;u<=h;u++){
   for(ll r=1;r<=w;r++){
    for(ll le=r+2;le<=w;le++){
     ll side = inf;
     ll inner = 0;
     for(ll i=l+1;i<u;i++)for(ll j=r+1;j<le;j++) inner = max( inner , e[i][j] );

     for(ll i=l;i<=u;i++) side = min( side , min( e[i][r] , e[i][le] ) );
     for(ll i=r;i<=le;i++) side = min( side , min( e[l][i] , e[u][i] ) );

     if( inner < side ){
      ll cnt = 0;
     for(ll i=l+1;i<u;i++)for(ll j=r+1;j<le;j++) cnt += side - e[i][j];

      res = max( res , cnt );
     }
    }
   }
  }
 }

 cout<<res<<endl;

 }
    return 0;
}