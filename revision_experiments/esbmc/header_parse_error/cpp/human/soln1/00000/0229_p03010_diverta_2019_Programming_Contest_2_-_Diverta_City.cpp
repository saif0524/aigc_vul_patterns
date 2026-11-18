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
long long a1[13]={1,2,4,7,12,20,29,38,52,101},a2[13]={1,2,4,7,12,20,30,39,67,101},n,an[15][15],no=1;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)an[i][i]=0;
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++)an[i][j]=an[j][i]=no*a1[j-i-1];
		no*=a2[n-i];
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)cout<<an[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}