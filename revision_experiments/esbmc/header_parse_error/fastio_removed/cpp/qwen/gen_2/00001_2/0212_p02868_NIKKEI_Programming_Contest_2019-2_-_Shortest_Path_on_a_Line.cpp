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
typedef pair<ll, ll> pll;

const ll inf = 1e18;

int main(){
    ((void)0);
    ((void)0);
    int N, M;
    cin >> N >> M;
    vector<ll> min_cost(N+1, inf);
    min_cost[1] = 0;
    vector<vector<pll>> diff(N+1);
    for(int i=0;i<M;i++){
        int L, R;
        ll C;
        cin >> L >> R >> C;
        diff[L].push_back({R, C});
    }
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        ll current_cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(current_cost > min_cost[u]) continue;
        for(auto [v, additional_cost] : diff[u]){
            ll new_cost = current_cost + additional_cost;
            if(new_cost < min_cost[v]){
                min_cost[v] = new_cost;
                pq.push({new_cost, v});
            }
        }
    }
    if(min_cost[N] == inf) cout << -1 << "\n";
    else cout << min_cost[N] << "\n";
}