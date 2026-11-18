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
    int H, W;
    cin >> H >> W;
    vector<vector<int>> mat(H, vector<int>(W));
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> mat[i][j];
        }
    }
    vector<int> dp(W, 0);
    int ans = 0;
    for(int i=0; i<H; i++){
        stack<pair<int, int>> st;
        for(int j=0; j<W; j++){
            if(mat[i][j] == 1) dp[j] = 0;
            else dp[j]++;
            while(!st.empty() && st.top().second >= dp[j]){
                int height = st.top().second;
                st.pop();
                int width = st.empty() ? j : j - st.top().first - 1;
                ans = max(ans, height * width);
            }
            st.push({j, dp[j]});
        }
        while(!st.empty()){
            int height = st.top().second;
            st.pop();
            int width = st.empty() ? W : W - st.top().first - 1;
            ans = max(ans, height * width);
        }
    }
    cout << ans;
}