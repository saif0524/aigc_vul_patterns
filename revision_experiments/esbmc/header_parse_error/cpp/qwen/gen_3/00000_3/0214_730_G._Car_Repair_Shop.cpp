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
    int n;
    cin >> n;
    vector<pair<long long, long long>> requests(n);
    for(auto &r : requests){
        cin >> r.first >> r.second;
    }
    set<pair<long long, long long>> schedule;
    for(const auto &[s, d] : requests){
        auto it = schedule.lower_bound({s, 0});
        if(it == schedule.begin() || (--it)->second < s){
            schedule.insert({s, s+d});
            cout << s << " " << s+d-1 << "\n";
        }
        else{
            ++it;
            long long start = 1;
            if(it != schedule.begin()){
                start = max(start, (--it)->second + 1);
            }
            while(it != schedule.end() && start + d > it->first){
                start = it->second + 1;
                ++it;
            }
            schedule.insert({start, start+d});
            cout << start << " " << start+d-1 << "\n";
        }
    }
}