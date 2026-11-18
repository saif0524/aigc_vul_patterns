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

int main(){
    ((void)0);
    ((void)0);
    int N;
    ll D;
    cin >> N >> D;
    vector<ll> A(N);
    for(auto &a : A) { cin >> a; }
    ll ans = 0;
    ll pref = 0;
    for(int i=1;i<N;i++){
        ll cost = min(D*i + A[i], D*(N-i) + A[i-1]);
        ans += cost;
        pref += cost;
    }
    ans -= min(D*(N-1) + A[N-1], D*(N-1) + A[0]);
    ll suf = 0;
    for(int i=N-2;i>=0;i--){
        ll cost = min(D*(N-i-1) + A[i], D*(N-i-1) + A[N-1]);
        suf += cost;
        ans = min(ans, pref + suf - min(D*(N-i-1) + A[i], D*(N-i-1) + A[N-1]));
    }
    cout << ans;
}