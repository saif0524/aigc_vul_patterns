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
#define ll long long
#define mex 400005
#define pi pair<int,int>
#define minmax(a,b) {min(a,b),max(a,b)}
int main() {
	// your code goes here
	int n;
	cin>>n;
	cout<<"? 1\n";
	cout.flush();
	int a[n];
	map<int,vector<int> > h;
	for(int i=0;i<n;i++) cin>>a[i],h[a[i]].push_back(i);
	set<pi> ed;
	int oc=0,ec=0;
	for(int i=0;i<n;i++)  if(i&1) oc += h[i].size();else ec += h[i].size();
	int in =2;
	if(ec > oc) in--;
	for(int x: h[1]) { ed.insert({0,x}); }
	for(int i=in;i<n;i+=2)
	{
	    if(ed.size() == n-1) break;
	    for(int x:h[i])
	    {
	        cout<<"? "<<x+1<<'\n';
	        cout.flush();
	        for(int i=0;i<n;i++) {
	            cin>>a[i];
	            if(a[i] == 1) ed.insert(minmax(x,i));
	        }
	    }
	}
	cout<<"!\n";
	auto it = ed.begin();
	while(it != ed.end())
	{
	    cout<<(*it).first + 1 << ' ' << (*it).second+1<<'\n';
	    it++;
	}
	return 0;
}