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
    long long n;
    cin >> n;
    vector<pair<long long, int>> events;
    for(long long i=0;i<n;i++){
        long long l, r;
        cin >> l >> r;
        events.emplace_back(l, 1);
        events.emplace_back(r+1, -1);
    }
    sort(events.begin(), events.end());
    vector<long long> count_cover(n+1, 0);
    long long current = 0;
    for(auto& [pos, change] : events){
        count_cover[current] += change > 0 ? pos - events[distance(events.begin(), lower_bound(events.begin(), events.end(), make_pair(pos, 0)))-1] : pos - events[distance(events.begin(), lower_bound(events.begin(), events.end(), make_pair(pos, 0))) - 2] - 1;
        current += change;
    }
    for(long long i=1;i<=n;i++){
        cout << count_cover[i] << " ";
    }
}