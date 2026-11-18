#include<iostream>
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
#include <cmath>

#define ll long long int
#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define fi first
#define se second
#define inf INT_MAX

#define FASTIO ((void)0);((void)0);
#define all(v) v.begin(),v.end()

#define sumof(v) accumulate(all(v), 0LL, plus<ll>())
#define maxof(v) max_element(all(v))
#define minof(v) min_element(all(v))


#define Vl vector<ll>
#define Vlp vector<pair<ll,ll>>
#define Vll vector<vector<ll>>
#define Vi vector<int>
#define Vip vector<pair<int,int>>
#define Vii vector<vector<int>>

#define repU(i,x,y,d) for(int i=x;i<y;i+=d)
#define repD(i,x,y,d) for(int i=x;i>=y;i-=d)

using namespace std;

int n;

int main(){
    FASTIO
    int t=1;
    cin>>t;

    while(t--){
        ll val;
        cin>>n;
        ll sm=0;
        repU(i,0,n,1){cin>>val;sm+=val;}

        if(sm%n){
            cout<<(sm%n)*(n-(sm%n))<<'\n';
        }
        else cout<<0<<'\n';

    }
    return 0;
}