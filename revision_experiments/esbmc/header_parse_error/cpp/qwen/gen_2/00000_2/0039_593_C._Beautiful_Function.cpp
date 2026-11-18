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
    int n;
    cin >> n;
    vector<tuple<int, int, int>> circles(n);
    for(auto& [x, y, r] : circles) cin >> x >> y >> r;
    vector<int> fs;
    vector<int> gs;
    for(int x = 0; x <= 50; x++){
        for(int y = 0; y <= 50; y++){
            bool valid = true;
            for(auto [cx, cy, cr] : circles){
                if((x - cx) * (x - cx) + (y - cy) * (y - cy) > cr * cr){
                    valid = false;
                    break;
                }
            }
            if(valid){
                fs.push_back(x);
                gs.push_back(y);
                if((int)fs.size() >= 51) break;
            }
        }
        if((int)fs.size() >= 51) break;
    }
    assert((int)fs.size() >= n);
    cout << "abs(";
    for(int i = 0; i < 51; i++){
        if(i) cout << "+";
        cout << "(t-" << fs[i] << ")";
    }
    cout << ")\n";
    cout << "abs(";
    for(int i = 0; i < 51; i++){
        if(i) cout << "+";
        cout << "(t-" << gs[i] << ")";
    }
    cout << ")\n";
}