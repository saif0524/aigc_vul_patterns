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
    vector<string> grid(H);
    for(int i=0;i<H;i++){
        cin >> grid[i];
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(grid[i][j] == '#'){
                bool valid = false;
                if(i+1 < H && grid[i+1][j] == '#') valid = true;
                if(i-1 >= 0 && grid[i-1][j] == '#') valid = true;
                if(j+1 < W && grid[i][j+1] == '#') valid = true;
                if(j-1 >= 0 && grid[i][j-1] == '#') valid = true;
                if(!valid){
                    cout << "No";
                    return 0;
                }
            }
        }
    }
    cout << "Yes";
}