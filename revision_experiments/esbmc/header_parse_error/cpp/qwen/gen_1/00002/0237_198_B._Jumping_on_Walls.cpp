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
    int n, k;
    cin >> n >> k;
    string left, right;
    cin >> left >> right;
    vector<vector<bool>> vis(n + 1, vector<bool>(2, false));
    queue<tuple<int,int,int>> q;
    q.push({0, 0, 0});
    vis[0][0] = true;
    while(!q.empty()){
        auto [time, pos, wall] = q.front();
        q.pop();
        if(pos > n) {
            cout << "YES";
            return 0;
        }
        if(time == n) continue;
        int next_pos = pos + 1;
        if(next_pos <= n && !vis[next_pos][wall] && (wall == 0 ? left[next_pos - 1] : right[next_pos - 1]) == '-'){
            q.push({time + 1, next_pos, wall});
            vis[next_pos][wall] = true;
        }
        next_pos = pos - 1;
        if(next_pos > 0 && !vis[next_pos][wall] && (wall == 0 ? left[next_pos - 1] : right[next_pos - 1]) == '-'){
            q.push({time + 1, next_pos, wall});
            vis[next_pos][wall] = true;
        }
        int jump_pos = pos + k;
        if(jump_pos <= n && !vis[jump_pos][1 - wall] && (1 - wall == 0 ? left[jump_pos - 1] : right[jump_pos - 1]) == '-'){
            q.push({time + 1, jump_pos, 1 - wall});
            vis[jump_pos][1 - wall] = true;
        }
    }
    cout << "NO";
}