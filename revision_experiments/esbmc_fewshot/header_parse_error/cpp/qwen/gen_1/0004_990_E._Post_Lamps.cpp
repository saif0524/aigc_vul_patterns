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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> blocked(m);
    for (int &x : blocked) cin >> x;
    
    vector<int> costs(k);
    for (int &c : costs) cin >> c;
    
    vector<bool> is_blocked(n + 1, false);
    for (int x : blocked) is_blocked[x] = true;
    
    long long min_cost = LLONG_MAX;
    
    for (int p = 1; p <= k; ++p) {
        long long total_cost = 0;
        int i = 0;
        
        while (i < n) {
            if (is_blocked[i]) {
                i++;
                continue;
            }
            
            bool found = false;
            for (int j = min(n, i + p); j > i; --j) {
                if (!is_blocked[j - 1]) {
                    total_cost += costs[p - 1];
                    i = j;
                    found = true;
                    break;
                }
            }
            
            if (!found) break;
        }
        
        if (i >= n) min_cost = min(min_cost, total_cost);
    }
    
    if (min_cost == LLONG_MAX) cout << -1;
    else cout << min_cost;
    
    return 0;
}