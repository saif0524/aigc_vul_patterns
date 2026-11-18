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
    int d, w;
    while(cin >> d >> w && (d || w)){
        vector<vector<int>> grid(d, vector<int>(w));
        for(int i = 0; i < d; ++i){
            for(int j = 0; j < w; ++j){
                cin >> grid[i][j];
            }
        }
        
        int maxCapacity = 0;
        for(int x1 = 0; x1 < d-2; ++x1){
            for(int y1 = 0; y1 < w-2; ++y1){
                for(int x2 = x1+2; x2 < d; ++x2){
                    for(int y2 = y1+2; y2 < w; ++y2){
                        int minHeight = 10;
                        for(int i = x1; i <= x2; ++i){
                            for(int j = y1; j <= y2; ++j){
                                if(i == x1 || i == x2 || j == y1 || j == y2){
                                    minHeight = min(minHeight, grid[i][j]);
                                }
                            }
                        }
                        int currentCapacity = 0;
                        bool valid = true;
                        for(int i = x1+1; i < x2 && valid; ++i){
                            for(int j = y1+1; j < y2 && valid; ++j){
                                if(grid[i][j] >= minHeight){
                                    valid = false;
                                } else {
                                    currentCapacity += minHeight - grid[i][j];
                                }
                            }
                        }
                        if(valid){
                            maxCapacity = max(maxCapacity, currentCapacity);
                        }
                    }
                }
            }
        }
        cout << maxCapacity << "\n";
    }
    return 0;
}