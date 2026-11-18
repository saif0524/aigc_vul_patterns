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
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> compressed(n);
    for(auto &s: compressed) cin >> s;

    auto is_compression_possible = [&](int x){
        vector<vector<bool>> matrix(n, vector<bool>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n/4; j++){
                char hex = compressed[i][j];
                int val = (hex >= 'A' && hex <= 'F') ? (hex - 'A' + 10) : (hex - '0');
                for(int k=0; k<4; k++){
                    matrix[i][4*j+k] = (val & (1 << (3-k))) > 0;
                }
            }
        }
        for(int i=0; i<n; i+=x){
            for(int j=0; j<n; j+=x){
                bool val = matrix[i][j];
                for(int ii=0; ii<x; ii++){
                    for(int jj=0; jj<x; jj++){
                        if(matrix[i+ii][j+jj] != val) return false;
                    }
                }
            }
        }
        return true;
    };

    int ans = 1;
    for(int x=2; x<=n; x*=2){
        if(n % x == 0 && is_compression_possible(x)){
            ans = x;
        }
    }
    cout << ans;
}