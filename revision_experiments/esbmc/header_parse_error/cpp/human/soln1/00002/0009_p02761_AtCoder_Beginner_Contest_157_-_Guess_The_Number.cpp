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
int n,m;
int a[10];
int main(){
	cin>>n>>m;
	memset(a,-1,sizeof a);
	int f=1;
	while(m--){
		int pos,c;
		cin>>pos>>c;
		if(a[pos]!=-1&&c!=a[pos]){
			f=0;
			break;
		}
		else a[pos]=c;
	}
	if(n==1){
		if(a[1]==-1)a[1]=0;
	}
	else{
		if(a[1]==0){
			f=0;
		}
		if(a[1]==-1)a[1]=1;
		for(int i=2;i<=n;i++){
			if(a[i]==-1)a[i]=0;
		}
	}
	if(!f)cout<<"-1"<<endl;
	else{
		for(int i=1;i<=n;i++)cout<<a[i];
		cout<<endl;
	}
	return 0;
}