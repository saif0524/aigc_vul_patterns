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
    ((void)0);
    ((void)0);
    int n;
    cin >> n;
    vector<pair<long long, long long>> products(n);
    for(auto &p : products){
        cin >> p.first >> p.second;
    }
    sort(products.begin(), products.end(), [](const pair<long long, long long> &a, const pair<long long, long long> &b){
        return a.first * 2 + max(0LL, (a.first - a.second) / (a.second + 1)) < b.first * 2 + max(0LL, (b.first - b.second) / (b.second + 1));
    });
    long long totalCost = 0, discount = 0;
    for(const auto &p : products){
        long long toBuy = p.first;
        if(discount >= p.first){
            totalCost += p.first;
            discount -= p.first;
        } else {
            totalCost += discount * 1 + (p.first - discount) * 2;
            discount = 0;
            long long afterBuy = toBuy;
            discount += afterBuy / (p.second + 1);
        }
    }
    cout << totalCost;
}