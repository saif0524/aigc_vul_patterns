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
    
    vector<string> park(n);
    for (int i = 0; i < n; ++i) {
        cin >> park[i];
    }
    
    vector<pair<int, int>> spiders;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (park[i][j] != '.') {
                spiders.push_back({i, j});
            }
        }
    }
    
    vector<int> ans(m, 0);
    
    for (int j = 0; j < m; ++j) {
        int spiders_seen = 0;
        vector<bool> spider_at_time(n * m, false);
        
        for (auto [si, sj] : spiders) {
            int time = 0;
            while (si >= 0 && si < n && sj >= 0 && sj < m) {
                if (si == 0 && sj == j) {
                    spider_at_time[time] = true;
                }
                if (park[si][sj] == 'L') sj--;
                else if (park[si][sj] == 'R') sj++;
                else if (park[si][sj] == 'U') si--;
                else if (park[si][sj] == 'D') si++;
                time++;
            }
        }
        
        int current_row = 0;
        int current_col = j;
        int time = 0;
        while (current_row < n && current_col >= 0 && current_col < m) {
            spiders_seen += spider_at_time[time];
            current_row++;
            time++;
        }
        
        ans[j] = spiders_seen;
    }
    
    for (int i = 0; i < m; ++i) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
    
    return 0;
}