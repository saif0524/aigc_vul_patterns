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

long long int gcd(long long int x,long long int y){
	while((x%=y)&&(y%=x));
	return x^y;
}

int main(){
	((void)0);
	((void)0);
	int T;
	cin>>T;
	while(T--){
		long long int A,B,C,D;
		cin>>A>>B>>C>>D;
		if(A<B||D<B){
			cout<<"No\n";
			continue;
		}
		long long int g = gcd(B,D);
		A = A - (C-B+1);
		long long int d = (A%g+g)%g;
			A = C-B+1+d;
		if(A<0)
			cout<<"No\n";
		else
			cout<<"Yes\n";
	}
}