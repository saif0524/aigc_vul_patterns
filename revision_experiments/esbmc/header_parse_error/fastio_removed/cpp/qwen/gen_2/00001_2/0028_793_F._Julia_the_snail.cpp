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
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> ropes(m);
    for(auto &r : ropes) cin >> r.first >> r.second;
    sort(ropes.begin(), ropes.end(), [](const pair<int,int>& a, const pair<int,int>& b){
        return a.first < b.first;
    });
    vector<int> max_reach(n+1, 0);
    int current_max = 0;
    for(int i=1;i<=n;i++){
        while(!ropes.empty() && ropes.front().first <= i){
            current_max = max(current_max, ropes.front().second);
            ropes.erase(ropes.begin());
        }
        max_reach[i] = current_max;
        current_max = max(current_max, max_reach[i-1]);
    }
    int q;
    cin >> q;
    while(q--){
        int x, y;
        cin >> x >> y;
        int ans = x;
        for(int i=x;i<=y;){
            ans = max(ans, max_reach[i]);
            if(max_reach[i] <= i) break;
            i = max_reach[i];
        }
        cout << ans << "\n";
    }
}