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

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s += s;
    
    int min_swaps = n;
    int h_count = 0, t_count = 0;
    
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'H') h_count++;
        else t_count++;
    }
    
    int current_h = 0, current_t = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'H') current_h++;
        else current_t++;
    }
    
    for (int i = 0; i < n; ++i) {
        int swaps = min(current_h, t_count - current_t);
        min_swaps = min(min_swaps, swaps);
        
        if (s[i] == 'H') current_h--;
        else current_t--;
        
        if (s[i + n] == 'H') current_h++;
        else current_t++;
    }
    
    cout << min_swaps << endl;
    return 0;
}