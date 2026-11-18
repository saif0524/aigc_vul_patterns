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
    
    int n, m, h;
    cin >> n >> m >> h;
    
    vector<int> u(n);
    for(int &x: u) cin >> x;
    
    vector<vector<int>> clients(n, vector<int>(h, 0));
    for(int i = 0; i < m; ++i) {
        int c1, c2;
        cin >> c1 >> c2;
        --c1; --c2;
        clients[c1][(u[c2] + 1) % h] ++;
        clients[c2][(u[c1] + 1) % h] ++;
    }
    
    vector<pair<int, int>> shifts;
    for(int i = 0; i < n; ++i) {
        int max_shift = -1;
        for(int j = 0; j < h; ++j) {
            max_shift = max(max_shift, clients[i][j]);
        }
        shifts.push_back({-max_shift, i});
    }
    
    sort(shifts.begin(), shifts.end());
    
    int k = 0;
    vector<int> answer;
    for(const auto &[cnt, idx]: shifts) {
        answer.push_back(idx + 1);
        ++k;
        bool valid = true;
        for(int i = 0; i < m; ++i) {
            int c1, c2;
            cin >> c1 >> c2;
            --c1; --c2;
            if(u[c1] == u[c2]) valid = false;
        }
        if(valid) break;
    }
    
    cout << k << "\n";
    for(int x: answer) cout << x << " ";
    cout << "\n";
    
    return 0;
}