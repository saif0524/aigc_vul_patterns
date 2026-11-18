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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> marks(2*n+1, vector<int>(2*m+1, 0));
    int total = (n*m + (n+m)%2)*2;
    int used = 0;
    auto in_bounds = [&](int x, int y){
        return 1 <= x && x <= 2*n && 1 <= y && y <= 2*m;
    };
    for(int i = 0; i < q; ++i){
        int x, y;
        cin >> x >> y;
        if((x+y)%2 == 0){
            if(marks[x][y] == 0){
                marks[x][y] = 1;
                used++;
                int cnt = 0;
                for(int dx = -1; dx <= 1; ++dx){
                    for(int dy = -1; dy <= 1; ++dy){
                        if((dx || dy) && in_bounds(x+dx, y+dy) && (x+dx+y+dy)%2 == 0){
                            if(marks[x+dx][y+dy] == 0){
                                cnt++;
                            }
                        }
                    }
                }
                if(cnt < 3){
                    cout << "YES\n";
                }
                else{
                    cout << "NO\n";
                }
            }
        }
    }
}