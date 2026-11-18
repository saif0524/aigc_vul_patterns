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
    int N;
    cin >> N;
    vector<pair<int, int>> pos(N, {0, 0});
    for(int i = 1; i < N; i++){
        int n, d;
        cin >> n >> d;
        if(d == 0){
            pos[i] = {pos[n].first - 1, pos[n].second};
        }
        else if(d == 1){
            pos[i] = {pos[n].first, pos[n].second - 1};
        }
        else if(d == 2){
            pos[i] = {pos[n].first + 1, pos[n].second};
        }
        else if(d == 3){
            pos[i] = {pos[n].first, pos[n].second + 1};
        }
    }
    int min_x = INT_MAX, max_x = INT_MIN, min_y = INT_MAX, max_y = INT_MIN;
    for(auto &p : pos){
        min_x = min(min_x, p.first);
        max_x = max(max_x, p.first);
        min_y = min(min_y, p.second);
        max_y = max(max_y, p.second);
    }
    cout << (max_x - min_x + 1) * (max_y - min_y + 1) << "\n";
}