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

ll simulate(ll n, ll k, bool op) {
    if (op) {
        if (k <= n / 2) {
            return k + n / 2;
        } else {
            return (k - n / 2) * 2 - 1;
        }
    } else {
        if (k <= n / 2) {
            return k * 2 - 1;
        } else {
            return (k - n / 2) * 2;
        }
    }
}

int main(){
    ((void)0);
    ((void)0);
    ll n, q, k, d;
    cin >> n >> q >> k >> d;
    vector<int> ops;
    for(int i=0;i<q;i++){
        bool op = (i % 2 == 0);
        ll nk = simulate(n, k, op);
        if(nk == d){
            for(int j=0;j<=i;j++){
                cout << (j % 2) << "\n";
            }
            return 0;
        }
        k = nk;
    }
    cout <<-1
;
    return 0;
}