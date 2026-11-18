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

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    ll lhs = (ll)(a.first - a.second) * (ll)b.second;
    ll rhs = (ll)(b.first - b.second) * (ll)a.second;
    return lhs > rhs;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, c, d;
    cin >> n >> c >> d;
    vector<pair<int, int>> students(n);
    for(auto& [ri, wi]: students){
        cin >> ri >> wi;
        ri -= c;
        wi -= d;
    }
    sort(students.begin(), students.end(), compare);
    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            ll lhs = (ll)(students[i].first - students[j].second) * (ll)students[j].second;
            ll rhs = (ll)(students[j].first - students[i].second) * (ll)students[i].second;
            if(lhs <= rhs) continue;
            for(int k = j+1; k < n; ++k){
                lhs = (ll)(students[i].first - students[k].second) * (ll)students[k].second;
                rhs = (ll)(students[k].first - students[i].second) * (ll)students[i].second;
                if(lhs <= rhs) continue;
                lhs = (ll)(students[j].first - students[k].second) * (ll)students[k].second;
                rhs = (ll)(students[k].first - students[j].second) * (ll)students[j].second;
                if(lhs > rhs){
                    ans++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}