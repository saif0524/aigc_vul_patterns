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

const int MAXN = 3005;

vector<int> adj[MAXN];
bool visited[MAXN];
int sz[MAXN];
double dp[MAXN];

void dfs(int u, int p) {
    sz[u] = 1;
    visited[u] = true;
    for (int v : adj[u]) {
        if (v != p && !visited[v]) {
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
}

double solve(int n) {
    if (n <= 1) return 0.0;
    double ans = n;
    fill(visited, visited + n, false);
    dfs(0, -1);
    fill(dp, dp + n, 0.0);
    for (int i = 0; i < n; ++i) {
        vector<double> contrib;
        for (int v : adj[i]) {
            if (sz[v] > 0) {
                contrib.push_back(sz[v] / (double)(n - 1));
            }
        }
        if (contrib.size() > 0) {
            double sum = 0.0;
            for (double x : contrib) { sum += x; }
            for (int v : adj[i]) {
                if (sz[v] > 0) {
                    double p = sz[v] / (double)(n - 1);
                    dp[i] += p * (1 + dp[v] + solve(sz[v]) - solve(n) * p);
                }
            }
        }
    }
    double EXPECT = 0.0;
    for (int i = 0; i < n; ++i) {
        EXPECT += dp[i];
    }
    return ans + EXPECT / n;
}

int main(){
    ((void)0);
    ((void)0);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << fixed << setprecision(12) << solve(n) << "\n";
}