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
int main(){
  string a,b;
  int c,d;
  int dp[2][5000],ans;
  while(cin>>a>>b){
    c=a.size(),d=b.size();
    ans=0;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=c;i++){
      for(int j=1;j<=d;j++){
	int ni=i%2,ri=1-i%2;
	//niは今のaの文字数が奇数か偶数か dpテーブルの使い回しのため
	//riはniじゃない方←前の結果のdpテーブル
	if(a[i-1]==b[j-1]){//一致したら前の状態の前の文字のdpテーブルから値を引っ張ってくる
	  dp[ni][j]=dp[ri][j-1]+1;
	}
	else dp[ni][j]=0;//違うなら打ち切る
	ans=max(ans,dp[ni][j]);
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}