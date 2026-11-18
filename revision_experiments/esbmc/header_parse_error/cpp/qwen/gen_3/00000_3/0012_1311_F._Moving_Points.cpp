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
    cin >> n;
    vector<pair<long long, long long>> points(n);
    for(int i=0;i<n;i++) cin >> points[i].first;
    for(int i=0;i<n;i++) cin >> points[i].second;
    sort(points.begin(), points.end(), [](const pair<long long, long long> &a, const pair<long long, long long> &b){
        return a.second > b.second || (a.second == b.second && a.first < b.first);
    });
    long long sum = 0;
    vector<long long> prefix_min(n);
    prefix_min[0] = points[0].first;
    for(int i=1;i<n;i++) prefix_min[i] = min(prefix_min[i-1], points[i].first);
    for(int i=1;i<n;i++){
        sum += points[i].first - prefix_min[i-1];
    }
    cout << sum;
}