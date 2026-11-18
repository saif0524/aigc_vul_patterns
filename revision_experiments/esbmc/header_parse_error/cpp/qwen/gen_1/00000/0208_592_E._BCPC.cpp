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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll c, d;
    cin >> n >> c >> d;
    vector<pair<ll, ll>> speeds(n);
    for(auto &s : speeds) cin >> s.first >> s.second;
    for(auto &s : speeds) s.first -= c, s.second -= d;
    auto compare = [](const pair<ll, ll> &a, const pair<ll, ll> &b){
        return a.first * b.second > a.second * b.first;
    };
    sort(speeds.begin(), speeds.end(), compare);
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(speeds[i].first * speeds[j].second <= speeds[i].second * speeds[j].first) continue;
            int pos = upper_bound(speeds.begin() + j + 1, speeds.end(), speeds[i], compare) - speeds.begin();
            if(pos > j) ans += (pos - j - 1);
        }
    }
    cout << ans;
}