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
    int n, m;
    cin >> n >> m;
    vector<string> table(n);
    for(auto &s: table) cin >> s;
    int r, c;
    cin >> r >> c;
    vector<string> pattern(r);
    for(auto &p: pattern) cin >> p;
    vector<vector<int>> ans(n, vector<int>(m, 0));
    for(int si=0; si<n; si++){
        for(int sj=0; sj<m; sj++){
            bool match = true;
            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                    if(pattern[i][j] != '?' && pattern[i][j] != table[(si+i)%n][(sj+j)%m]){
                        match = false;
                        break;
                    }
                }
                if(!match) break;
            }
            if(match) ans[si][sj] = 1;
        }
    }
    for(auto &row: ans){
        for(int x: row) cout << x;
        cout << '\n';
    }
}