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
    vector<string> target(n);
    for(auto &row : target) { cin >> row; }
    
    vector<string> current(n, string(n, '0'));
    int commands = 0;
    
    for(int x = 0; x < n; ++x){
        for(int y = 0; y < n; ++y){
            if(current[x][y] != target[x][y]){
                ++commands;
                for(int i = x; i <= y; ++i){
                    current[x][i] = (current[x][i] == '0') ? '1' : '0';
                    current[i][y] = (current[i][y] == '0') ? '1' : '0';
                }
            }
        }
    }
    
    cout << commands;
}