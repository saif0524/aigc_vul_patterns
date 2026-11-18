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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin >> n;
    vector<pair<long long, long long>> products(n);
    for(auto &p: products){
        cin >> p.first >> p.second;
    }
    sort(products.begin(), products.end(), [](const pair<long long, long long> &a, const pair<long long, long long> &b){
        return a.second < b.second;
    });
    long long total = 0;
    long long bought = 0;
    for(auto &p: products){
        long long need = p.first;
        long long bulk = p.second;
        long long full_bulks = bought / bulk;
        long long can_get_discount = full_bulks * bulk;
        long long pay_full_price = min(need, can_get_discount);
        total += pay_full_price * 2;
        need -= pay_full_price;
        bought += pay_full_price;
        long long pay_discount = need;
        total += pay_discount;
        bought += pay_discount;
    }
    cout << total;
}