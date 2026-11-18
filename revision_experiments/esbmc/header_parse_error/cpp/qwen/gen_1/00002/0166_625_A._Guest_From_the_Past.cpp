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
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    ll ans = 0;
    if(a < b){
        ans = n / a;
    }
    else{
        ll glass_bottles = n / b;
        ll money_left = n % b + glass_bottles * c;
        ans += glass_bottles;
        while(money_left >= b){
            ll new_glass_bottles = money_left / b;
            ll new_money_left = money_left % b + new_glass_bottles * c;
            ans += new_glass_bottles;
            money_left = new_money_left;
        }
    }
    cout << ans;
}