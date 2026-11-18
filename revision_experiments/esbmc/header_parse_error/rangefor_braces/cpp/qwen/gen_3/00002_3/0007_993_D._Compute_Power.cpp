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
    vector<int> a(n), b(n);
    for(auto &x: a) { cin >> x; }
    for(auto &x: b) { cin >> x; }
    vector<pair<int, int>> tasks(n);
    for(int i=0; i<n; ++i) tasks[i] = {a[i], b[i]};
    sort(tasks.begin(), tasks.end(), [&](auto &x, auto &y){
        if(x.first != y.first) return x.first > y.first;
        return x.second < y.second;
    });
    double threshold = 0;
    int total_power = 0, total_processors = 0;
    for(int i=0, j=i+1; i<n; i=j){
        total_power += tasks[i].first;
        total_processors += tasks[i].second;
        j++;
        while(j<n && tasks[j].first < tasks[i].first){
            total_power += tasks[j].first;
            total_processors += tasks[j].second;
            double current_avg = (double)total_power / total_processors;
            threshold = max(threshold, current_avg);
            j++;
        }
        total_power -= tasks[i].first;
        total_processors -= tasks[i].second;
    }
    threshold *= 1000;
    threshold = ceil(threshold);
    cout << (int)threshold;
}