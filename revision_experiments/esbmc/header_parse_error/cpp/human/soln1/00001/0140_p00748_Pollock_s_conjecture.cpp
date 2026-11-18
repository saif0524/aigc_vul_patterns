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
using ll = long long;
const int MOD = 1e9+7;
template<class T>bool chmin(T &a, const T &b)
{ return (a>b ? (a=b)||1 : 0); }

int main(){
	
	vector<int> d,e;
	for(int i=1; i<=200; i++){
		int m = i*(i+1)*(i+2)/6;
		d.push_back(m);
		if(m%2) e.push_back(m);
	}
	vector<int> dp1(1000001,1e8);
	vector<int> dp2(1000001,1e8);
	dp1.at(0) = 0;
	dp2.at(0) = 0;
	for(int i=0; i<=1000000; i++){
		for(auto j:d){
			if(i+j<=1e6){
				chmin(dp1.at(i+j),dp1.at(i)+1);
			}
		}
		for(auto j:e){
			if(i+j<=1e6){
				chmin(dp2.at(i+j),dp2.at(i)+1);
			}
		}
	}
	while(1){
		int n; cin>>n;
		if(!n) break;
		cout << dp1.at(n)<<' '<<dp2.at(n)<<endl;
	}
	
}