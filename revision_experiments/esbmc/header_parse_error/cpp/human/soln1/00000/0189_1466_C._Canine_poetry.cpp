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
#define FOR(i, st, n) for (int i = st; i < n; i++)
const int INF = 1e9+100;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin>>t;
	while (t--){
		string s;
		cin>>s;
		int n = s.size();
		int ans = 0;
		for (int i = 0; i < n-1; i++){
			if (i < n-2 && s[i] == s[i+1] && s[i] == s[i+2]){
				ans+=2;
				i += 2;
			}else if(s[i] == s[i+1]){
				ans++;
				i++;
			}else if(i < n-2 && s[i] == s[i+2]){
				ans++;
				if (i < n-3 && s[i+1] == s[i+3]){
					ans++;
					i+=3;
				}else{
					i+=2;
				}
			}
		}
		cout<<ans<<'\n';

	}

	return 0;
}