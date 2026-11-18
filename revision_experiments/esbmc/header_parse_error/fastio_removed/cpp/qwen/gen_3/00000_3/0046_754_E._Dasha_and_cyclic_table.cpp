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
    ((void)0);
    ((void)0);
    int n, m;
    cin >> n >> m;
    vector<string> table(n);
    for(int i=0;i<n;i++) cin >> table[i];
    int r, c;
    cin >> r >> c;
    vector<string> pattern(r);
    for(int i=0;i<r;i++) cin >> pattern[i];
    vector<vector<char>> result(n, vector<char>(m, '0'));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            bool match = true;
            for(int x=0;x<r && match;x++){
                for(int y=0;y<c && match;y++){
                    if(pattern[x][y] != '?' && pattern[x][y] != table[(i+x)%n][(j+y)%m]){
                        match = false;
                    }
                }
            }
            if(match) result[i][j] = '1';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout << result[i][j];
        cout << "\n";
    }
}