/*** author: yuji9511 ***/
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
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll ue = 0, migi = 0;
    rep(i,0,N){
        if(S[i] >= 'A' && S[i] <= 'M'){
            ue++;
        }else if(S[i] >= 'N' && S[i] <= 'Z'){
            ue--;
        }else if(S[i] >= 'a' && S[i] <= 'm'){
            migi++;
        }else{
            migi--;
        }
    }
    ll sz = abs(ue) + abs(migi);
    print(sz);
    rep(i,0,abs(ue)){
        if(ue > 0){
            cout << 'A';
        }else{
            cout << 'N';
        }
    }
    rep(i,0,abs(migi)){
        if(migi > 0){
            cout << 'a';
        }else{
            cout << 'n';
        }
    }
    cout << endl;

    
}