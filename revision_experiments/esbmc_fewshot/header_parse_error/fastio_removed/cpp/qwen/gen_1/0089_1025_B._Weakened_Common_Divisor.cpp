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

const int MAXN = 150005;
const int MAXP =10000000;

vector<int> factors[MAXP + 1];

void sieve() {
    for (int i = 2; i <= MAXP; ++i) {
        if (factors[i].empty()) {
            for (int j = i; j <= MAXP; j += i) {
                factors[j].push_back(i);
            }
        }
    }
}

int main() {
    ((void)0);
    ((void)0);
    
    sieve();
    
    int n;
    cin >> n;
    
    unordered_map<int, int> commonFactors;
    
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        
        unordered_set<int> fa, fb;
        
        for (int f : factors[a]) {
            fa.insert(f);
        }
        
        for (int f : factors[b]) {
            fb.insert(f);
        }
        
        for (int f : fa) {
            if (fb.count(f)) {
                commonFactors[f]++;
            }
        }
    }
    
    int result = -1;
    
    for (auto& [factor, count] : commonFactors) {
        if (count == n) {
            result = factor;
            break;
        }
    }
    
    cout << result << "\n";
    
    return 0;
}