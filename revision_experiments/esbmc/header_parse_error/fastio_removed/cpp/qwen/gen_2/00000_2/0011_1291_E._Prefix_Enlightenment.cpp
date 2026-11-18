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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<int>> subsets(k);
    for(int i=0;i<k;i++){
        int c;
        cin >> c;
        subsets[i] = vector<int>(c);
        for(int j=0;j<c;j++){
            cin >> subsets[i][j];
            subsets[i][j]--;
        }
    }
    vector<int> oncnt(n, 0);
    for(int i=0;i<k;i++){
        for(int x : subsets[i]){
            oncnt[x]++;
        }
    }
    vector<vector<int>> indices(n);
    for(int i=0;i<k;i++){
        for(int x : subsets[i]){
            indices[x].push_back(i);
        }
    }
    vector<int> dp(k, 0);
    vector<int> ans(n, 0);
    for(int i=0;i<n;i++){
        if(s[i] == '1'){
            ans[i] = 0;
            continue;
        }
        int req = 1;
        for(int ind : indices[i]){
            if(dp[ind] == 1){
                req--;
            }
            dp[ind] ^= 1;
        }
        ans[i] = req;
    }
    for(int i=1;i<n;i++){
        ans[i] += ans[i-1];
    }
    for(int i=0;i<n;i++){
        cout << ans[i] << "\n";
    }
}