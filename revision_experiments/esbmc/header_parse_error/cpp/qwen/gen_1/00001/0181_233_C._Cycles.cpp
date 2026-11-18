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
    int k;
    cin >> k;
    int n = min(100, k*3);
    vector<vector<char>> g(n, vector<char>(n, '0'));
    int cnt = 0;
    for(int i=0; i<n && cnt < k; ++i){
        for(int j=i+1; j<n && cnt < k; ++j){
            for(int l=j+1; l<n && cnt < k; ++l){
                g[i][j] = g[j][i] = '1';
                g[j][l] = g[l][j] = '1';
                g[l][i] = g[i][l] = '1';
                ++cnt;
            }
        }
    }
    cout << n << "\n";
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cout << g[i][j];
        }
        cout << "\n";
    }
}