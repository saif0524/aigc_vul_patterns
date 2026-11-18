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
    vector<string> grid(n);
    for(auto &row: grid) { cin >> row; }

    vector<vector<int>> row_count(n, vector<int>(26, 0));
    vector<vector<int>> col_count(m, vector<int>(26, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            row_count[i][grid[i][j]-'a']++;
            col_count[j][grid[i][j]-'a']++;
        }
    }

    string result;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(row_count[i][grid[i][j]-'a'] == 1 && col_count[j][grid[i][j]-'a'] == 1){
                result += grid[i][j];
            }
        }
    }

    cout << result;
}