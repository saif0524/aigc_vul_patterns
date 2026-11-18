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
    int N, V;
    cin >> N >> V;
    vector<long long> x(N);
    for(auto &i: x) cin >> i;
    vector<string> result(N, "Impossible");
    
    for(int start = 0; start < N; ++start){
        int water = V;
        bool can_visit_all = true;
        long long current_pos = x[start];
        for(int i = 0; i < N; ++i){
            long long target_pos = x[i];
            long long distance = abs(target_pos - current_pos);
            if(water >= distance){
                water -= distance;
                current_pos = target_pos;
            }
            else{
                if(water == 0){
                    can_visit_all = false;
                    break;
                }
                while(water > 0 && water < distance){
                    water = water / 2;
                    if(water == 0){
                        can_visit_all = false;
                        break;
                    }
                }
                if(water >= distance){
                    water -= distance;
                    current_pos = target_pos;
                }
                else{
                    can_visit_all = false;
                    break;
                }
            }
        }
        if(can_visit_all) result[start] = "Possible";
    }
    
    for(const auto &r: result) cout << r << "\n";
    return 0;
}