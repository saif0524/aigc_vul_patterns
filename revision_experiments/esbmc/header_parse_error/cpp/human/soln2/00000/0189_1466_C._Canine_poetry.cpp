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
#define N 100005
typedef long long LL;
typedef unsigned long long  ULL; 
int main()
{
	int k,j,i,tt,temp;
	cin>>tt;
	while(tt--)
	{
		int n,a[N]={0},ans=0;
		char cha[N]={0},chb[1],ch;	
		cin>>cha+1;
		for(i=2;cha[i]!=0;i++)
		{
			if(cha[i]==cha[i-1]&&cha[i-1]!=1)
			{
				cha[i]=1;
				ans+=1;
			}
			if(cha[i-1]==cha[i+1]&&cha[i-1]!=1) 
			{
				cha[i+1]=1;
				ans+=1;
			 } 
		}
		cout<<ans<<endl;
		//cout<<endl;
	}
	return 0; 
 }