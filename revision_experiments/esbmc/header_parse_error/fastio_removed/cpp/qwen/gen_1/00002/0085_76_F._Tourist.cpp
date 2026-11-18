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
    vector<pair<int, int>> events(n);
    for(auto &e: events){
        cin >> e.first >> e.second;
    }
    int V;
    cin >> V;
    sort(events.begin(), events.end(), [](const pair<int, int>&a, const pair<int, int>&b){
        return a.second < b.second;
    });
    int maxEventsFromZero = 0;
    set<int> positions;
    positions.insert(0);
    for(auto &e: events){
        int x = e.first;
        int t = e.second;
        auto it = positions.lower_bound(x - V*t);
        if(it != positions.end() && *it <= x + V*t){
            maxEventsFromZero++;
            positions.insert(x);
        }
    }
    int maxEventsFromAnywhere = 0;
    positions.clear();
    for(auto &e: events){
        int x = e.first;
        int t = e.second;
        positions.insert(x);
        auto it = positions.lower_bound(x - V*t);
        if(it != positions.end() && *it <= x + V*t){
            maxEventsFromAnywhere = max(maxEventsFromAnywhere, (int)positions.size());
        }
    }
    cout << maxEventsFromZero << " " << maxEventsFromAnywhere;
}