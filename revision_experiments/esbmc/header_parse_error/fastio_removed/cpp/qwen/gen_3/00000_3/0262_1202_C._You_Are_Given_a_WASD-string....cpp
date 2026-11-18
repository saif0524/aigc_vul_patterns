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
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        int dx[] = {0, 0, 1, -1};
        int dy[] = {-1, 1, 0, 0};
        map<char, int> dir_map = {{'W', 0}, {'S', 1}, {'D', 2}, {'A', 3}};
        int min_x = 0, min_y = 0, max_x = 0, max_y = 0;
        int x = 0, y = 0;
        for(auto c : s){
            x += dx[dir_map[c]];
            y += dy[dir_map[c]];
            min_x = min(min_x, x);
            min_y = min(min_y, y);
            max_x = max(max_x, x);
            max_y = max(max_y, y);
        }
        int res = (max_x - min_x + 1) * (max_y - min_y + 1);
        for(char c : "WASD"){
            set<pair<int, int>> pos;
            pos.insert({0, 0});
            x = 0, y = 0;
            for(int i = 0; i <= s.size(); i++){
                if(i < s.size()){
                    x += dx[dir_map[s[i]]];
                    y += dy[dir_map[s[i]]];
                } else {
                    x += dx[dir_map[c]];
                    y += dy[dir_map[c]];
                }
                pos.insert({x, y});
            }
            int local_min_x = 0, local_min_y = 0, local_max_x = 0, local_max_y = 0;
            for(auto it : pos){
                local_min_x = min(local_min_x, it.first);
                local_min_y = min(local_min_y, it.second);
                local_max_x = max(local_max_x, it.first);
                local_max_y = max(local_max_y, it.second);
            }
            res = min(res, (local_max_x - local_min_x + 1) * (local_max_y - local_min_y + 1));
        }
        cout << res << "\n";
    }
}