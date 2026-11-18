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
    ll m;
    cin >> m;
    ll best_x = 0, best_blocks = 0;
    for(ll x=1;x*x*x<=m;x++){
        ll remaining = m;
        ll blocks = 0;
        for(ll i=x;i>=1;i--){
            ll cube = i*i*i;
            if(cube > remaining) continue;
            ll count = remaining / cube;
            blocks += count;
            remaining -= count * cube;
        }
        if(blocks > best_blocks || (blocks == best_blocks && x > best_x)){
            best_blocks = blocks;
            best_x = x*x*x;
        }
    }
    cout << best_blocks << " " << best_x << endl;
}