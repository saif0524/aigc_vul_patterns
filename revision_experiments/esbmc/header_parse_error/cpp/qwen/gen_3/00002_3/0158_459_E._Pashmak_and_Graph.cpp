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

const int N = 3e5 + 5;
const int W = 1e5 + 5;

int n, m;
vector<pair<int, int>> adj[N];
int dp[N][W];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }
    int ans = 0;
    for(int s = 1; s <= n; s++){
        queue<pair<int, int>> q;
        q.emplace(s, 0);
        fill(dp[s], dp[s] + W, -1);
        dp[s][0] = 0;
        while(!q.empty()){
            auto [u, w] = q.front();
            q.pop();
            for(auto [v, nw] : adj[u]){
                if(nw > w && dp[s][nw] < dp[s][w] + 1){
                    dp[s][nw] = dp[s][w] + 1;
                    q.emplace(v, nw);
                    ans = max(ans, dp[s][nw]);
                }
            }
        }
    }
    cout << ans;
}