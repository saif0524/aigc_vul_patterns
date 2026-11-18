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
#define lp(i,n) for(int i=0;i<n;i++)


int main(){
  while(1){
    int n;
    cin>>n;
    if(n==0) break;
    int a[50];
    string memo;
    lp(i,n){
      cin>>memo;
      a[i]=memo.size();
    }
    lp(i,n){
      int ans=0;
      int count=0,stats=0;
      for(int j=i;j<n;j++){
	if(stats==0||stats==2){
	  count+=a[j];
	  if(count==5){
	    stats++;
	    count=0;
	  }
	  if(count>5) break;
	}
	else if(stats==1||stats==3||stats==4){
	  count+=a[j];
	  if(count==7){
	    stats++;
	    count=0;
	  }
	  if(count>7) break;
	}
	if(stats==5) {
	  ans=1;
	  break;
	}
      }
      if(ans==1) {
	cout<<i+1<<endl;
	break;
      }
    }
  }
  return 0;
}