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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, q;
    cin >> n >> k >> q;
    vector<vector<int>> creatures(k+1, vector<int>(n));
    for(int i = 1; i <= k; ++i){
        for(int j = 0; j < n; ++j){
            cin >> creatures[i][j];
        }
    }
    int next_creature = k+1;
    while(q--){
        int t, x, y;
        cin >> t >> x >> y;
        if(t == 1){
            creatures.push_back(vector<int>(n));
            for(int j = 0; j < n; ++j){
                creatures[next_creature][j] = max(creatures[x][j], creatures[y][j]);
            }
            next_creature++;
        }
        else if(t == 2){
            creatures.push_back(vector<int>(n));
            for(int j = 0; j < n; ++j){
                creatures[next_creature][j] = min(creatures[x][j], creatures[y][j]);
            }
            next_creature++;
        }
        else{
            cout << creatures[x][y-1] << "\n";
        }
    }
}