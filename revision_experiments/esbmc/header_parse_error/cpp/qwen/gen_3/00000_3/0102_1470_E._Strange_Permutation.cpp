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
        int n, c, q;
        cin >> n >> c >> q;
        vector<int> p(n);
        for(auto &x : p) cin >> x;
        set<vector<int>> permutations;
        permutations.insert(p);
        for(int l = 0; l < n; ++l){
            for(int r = l+1; r <= n; ++r){
                if(r - l > c) continue;
                vector<int> np = p;
                reverse(np.begin()+l, np.begin()+r);
                permutations.insert(np);
            }
        }
        vector<vector<int>> sorted_permutations(permutations.begin(), permutations.end());
        while(q--){
            int i, j;
            cin >> i >> j;
            if(j > sorted_permutations.size()){
                cout << -1 << "\n";
            }else{
                cout << sorted_permutations[j-1][i-1] << "\n";
            }
        }
    }
}