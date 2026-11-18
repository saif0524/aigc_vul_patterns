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
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for(auto &s : a) { cin >> s; }
    vector<int> colCount(m, 0);
    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++) colCount[j] += a[i][j] - '0';
    }
    int minOnes = m * n;
    for(int mask=0; mask<(1<<n); mask++){
        int ones = 0;
        for(int j=0; j<m; j++){
            int onesInCol = colCount[j];
            int zerosInCol = n - onesInCol;
            int effectiveOnes = (mask & (1 << (n-1))) ? zerosInCol : onesInCol;
            ones += effectiveOnes;
        }
        minOnes = min(minOnes, ones);
    }
    cout << minOnes;
}