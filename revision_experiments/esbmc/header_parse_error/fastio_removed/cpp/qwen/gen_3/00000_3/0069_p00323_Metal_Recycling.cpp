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
    int N;
    cin >> N;
    vector<pair<long long, long long>> data(N);
    for(auto &d: data){
        cin >> d.first >> d.second;
        d.first = 2 * d.first;
        d.second = 2 * d.second;
    }
    long long total_weight = 0, total_lumps = 0;
    for(auto d: data){
        total_weight += d.first;
        total_lumps += d.second;
    }
    total_weight -= total_lumps;
    long long current_weight = 0, current_lumps = 0;
    sort(data.begin(), data.end());
    vector<pair<long long, long long>> result;
    for(auto d: data){
        if(current_weight + d.first <= total_weight){
            current_weight += d.first;
            current_lumps += d.second;
        } else {
            long long needed = total_weight - current_weight;
            long long remaining_weight = d.first - needed;
            long long remaining_lumps = d.second;
            current_lumps += needed / 2;
            result.emplace_back(current_weight + needed, current_lumps);
            result.emplace_back(remaining_weight, remaining_lumps - needed % 2);
            current_weight = 0;
            current_lumps = 0;
        }
    }
    if(current_weight > 0){
        result.emplace_back(current_weight, current_lumps);
    }
    for(auto r: result){
        cout << r.first / 2 << " " << r.second / 2 << "\n";
    }
}