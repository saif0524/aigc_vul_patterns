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
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<long long>> a(n, vector<long long>(m));
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                cin >> a[i][j];
            }
        }
        vector<vector<long long>> b(n, vector<long long>(m));
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                b[i][j] = a[i][j];
                if(i>0 && b[i][j]==b[i-1][j]){
                    b[i][j]++;
                }
                if(j>0 && b[i][j]==b[i][j-1]){
                    b[i][j]++;
                }
                if(i+1<n && b[i][j]==b[i+1][j]){
                    b[i+1][j]++;
                }
                if(j+1<m && b[i][j]==b[i][j+1]){
                    b[i][j+1]++;
                }
            }
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                cout << b[i][j] << (j==m-1?"\n":" ");
            }
        }
    }
}