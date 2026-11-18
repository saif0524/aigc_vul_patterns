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
    int k, n;
    cin >> k >> n;
    vector<pair<long long, long long>> stones(k);
    vector<pair<long long, long long>> monsters(n);
    
    for(auto &s: stones){
        cin >> s.first >> s.second;
    }
    
    for(auto &m: monsters){
        cin >> m.first >> m.second;
    }
    
    set<int> afraid_monsters;
    
    for(const auto &s: stones){
        for(int i = 0; i < n; ++i){
            const auto &[mx, my] = monsters[i];
            if(mx == s.first){
                bool can_hit = true;
                for(int j = 0; j < n; ++j){
                    if(i == j) continue;
                    const auto &[tx, ty] = monsters[j];
                    if(tx == s.first && ((my < s.second && ty > s.second) || (my > s.second && ty < s.second))){
                        can_hit = false;
                        break;
                    }
                }
                if(can_hit) afraid_monsters.insert(i);
            }
            else if(my == s.second){
                bool can_hit = true;
                for(int j = 0; j < n; ++j){
                    if(i == j) continue;
                    const auto &[tx, ty] = monsters[j];
                    if(ty == s.second && ((mx < s.first && tx > s.first) || (mx > s.first && tx < s.first))){
                        can_hit = false;
                        break;
                    }
                }
                if(can_hit) afraid_monsters.insert(i);
            }
            else{
                long double slope = (long double)(my - s.second) / (mx - s.first);
                long double intercept = s.second - slope * s.first;
                bool can_hit = true;
                for(int j = 0; j < n; ++j){
                    if(i == j) continue;
                    const auto &[tx, ty] = monsters[j];
                    long double y = slope * tx + intercept;
                    if(abs(y - ty) < 1e-9 && ((mx < s.first && tx > s.first) || (mx > s.first && tx < s.first))){
                        can_hit = false;
                        break;
                    }
                }
                if(can_hit) afraid_monsters.insert(i);
            }
        }
    }
    
    cout << afraid_monsters.size();
}