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
    int n;
    long long d;
    cin >> n >> d;
    vector<pair<long long, long long>> friends(n);
    for(auto &f: friends){
        cin >> f.first >> f.second;
    }
    sort(friends.begin(), friends.end());
    multiset<long long> s;
    long long max_sum = 0, current_sum = 0;
    for(const auto &f: friends){
        s.insert(f.second);
        current_sum += f.second;
        while(f.first - friends.front().first >= d){
            current_sum -= friends.front().second;
            s.erase(s.find(friends.front().second));
            friends.erase(friends.begin());
        }
        max_sum = max(max_sum, current_sum);
    }
    cout << max_sum;
}