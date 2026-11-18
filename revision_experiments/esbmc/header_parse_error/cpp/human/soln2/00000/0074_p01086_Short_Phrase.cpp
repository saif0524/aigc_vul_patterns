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
#define rep(i,n) for(int i=0; i<(n); i++)

using namespace std;

string str[41];
int k;
int n;

bool check(int p, int c)
{
	int cnt =0;
	for(int i=p;i<n;i++){
		cnt += str[i].length();
		k++;
		if(cnt == c) return true;
		else if(cnt > c)return false;
	}
	return false;
}

int main(){
	while(cin>>n, n){
		rep(i,n) cin >> str[i];
		rep(i,n){
			k = i;
			if(check(k,5) && check(k,7) && check(k,5) && check(k,7) && check(k,7)) {
				cout << i+1 << endl;
				break;
			}
		}
	}
	return 0;
}