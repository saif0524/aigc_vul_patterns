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
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    vector<pair<int,int>> targets;
    vector<int> row_used(n,0), col_used(n,0);
    for(int col=0;col<n;col++){
        if(a[col] > 3 || a[col] + col_used[col] > 2){
            cout << -1;
            return 0;
        }
        for(int i=0;i<a[col];i++){
            if(row_used[n-i-1] == 2){
                cout << -1;
                return 0;
            }
            targets.push_back({n-i-1,col});
            row_used[n-i-1]++;
            col_used[col]++;
        }
    }
    for(int i=0;i<n;i++){
        if(row_used[i] > 2){
            cout << -1;
            return 0;
        }
    }
    cout << targets.size() << "\n";
    for(auto [r,c]: targets){
        cout << r+1 << " " << c+1 << "\n";
    }
}