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
    int H, W;
    cin >> H >> W;
    vector<vector<int>> damage(H, vector<int>(W));
    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            cin >> damage[i][j];
        }
    }

    int si = -1, sj = -1, ti = -1, tj = -1;

    for(int i = 0; i <= H-3; ++i){
        for(int j = 0; j <= W-3; ++j){
            bool validStart = true;
            for(int x = 0; x < 3; ++x){
                for(int y = 0; y < 3; ++y){
                    if(damage[i+x][j+y] != min(3, x+y)){
                        validStart = false;
                    }
                }
            }
            if(validStart){
                si = i+1, sj = j+1;
            }
        }
    }

    for(int i = 0; i <= H-3; ++i){
        for(int j = 0; j <= W-3; ++j){
            bool validEnd = true;
            for(int x = 0; x < 3; ++x){
                for(int y = 0; y < 3; ++y){
                    if(damage[i+x][j+y] != max(0, 3-x-y)){
                        validEnd = false;
                    }
                }
            }
            if(validEnd){
                ti = i+1, tj = j+1;
            }
        }
    }

    if(si != -1 && sj != -1 && ti != -1 && tj != -1 && 10000 * ti + tj <= 10000 * si + sj){
        cout << si << " " << sj << " " << ti << " " << tj;
    }else{
        cout << "-1 -1 -1 -1";
    }

    return 0;
}