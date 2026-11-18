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
const int MOD = 1000000007;

map<pair<ll, ll>, int> slopes;

int main(){
    ((void)0);
    ((void)0);
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        ll A, B;
        cin >> A >> B;
        if(A==0){
            if(B==0) continue;
            slopes[{0,1}]++;
        }
        else{
            ll g = __gcd(A, B);
            A /= g;
            B /= g;
            ll sign = (A<0 || (A==0 && B<0))?-1:1;
            A *= sign;
            B *= sign;
            slopes[{A,B}]++;
        }
    }
    long long ans = 1;
    for(auto& [_, cnt] : slopes){
        ans = (ans * (1 + (1LL << cnt))) % MOD;
    }
    cout << (ans-1+MOD)%MOD << "\n";
    return 0;
}