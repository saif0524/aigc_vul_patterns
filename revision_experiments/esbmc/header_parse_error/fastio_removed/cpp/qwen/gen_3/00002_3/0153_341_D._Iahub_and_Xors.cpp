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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n+1, vector<int>(n+1, 0));
    for(int i=0; i<m; i++){
        int type;
        cin >> type;
        if(type == 1){
            int x0, y0, x1, y1;
            cin >> x0 >> y0 >> x1 >> y1;
            int result = 0;
            for(int row=x0; row<=x1; row++){
                for(int col=y0; col<=y1; col++){
                    result ^= mat[row][col];
                }
            }
            cout << result << "\n";
        } else {
            int x0, y0, x1, y1, v;
            cin >> x0 >> y0 >> x1 >> y1 >> v;
            for(int row=x0; row<=x1; row++){
                for(int col=y0; col<=y1; col++){
                    mat[row][col] ^= v;
                }
            }
        }
    }
}