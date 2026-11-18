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
using ll=long long;
#define                           pb                          push_back
#define                           fr(i,l,r)                   for(ll i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(ll i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           show(x,y)                   cout<<x<<" : ";for(auto z:y)cout<<z<<" ";cout<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define 						  all(x) 					  x.begin(),x.end()
#define 						  yes 	    				  cout<<"YES"<<endl
#define 						  no 	       				  cout<<"NO"<<endl
ll dp[5005][5005];
ll inf= 1e18;

void Test()
{

	int n;
	cin>>n;
	vector<ll>X,Y;
	X.pb(0);
	Y.pb(0);


	for(int i=1; i<=n; i++)
	{
		int x;
		cin>>x;
		if(x) X.pb(i);
		else Y.pb(i);
	}




	fr(i,1,n)
	fr(j,1,n)
	{
		dp[i][j]=inf;
		dp[i][0]=inf;

	}
	
	dp[0][0]=0;



	for(int i=1; i<X.size(); i++)
	{

		for(int j=1; j<Y.size(); j++)
		{

			ll cost= abs(X[i]-Y[j]) ;
			dp[i][j]= min(dp[i][j-1],dp[i-1][j-1]+ cost);    ;
		}
	}

	cout<<dp[X.size() - 1 ][Y.size() - 1]<<endl;









}


int main()
{

	int t=1;
	//cin>>t;

	while(t--)
		Test();

}