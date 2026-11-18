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

const int MAX_N = 100005;

vector<int> adj[MAX_N];
map<string, int> mp;
int ans[MAX_N];

string dfs(int u, int p) {
    string str = "";
    vector<string> child;
    for (int v : adj[u]) {
        if (v == p) continue;
        child.push_back(dfs(v, u));
    }
    sort(child.begin(), child.end());
    for (string s : child) {
        str += s + "#";
    }
    if (str == "") str = "0";
    mp[str]++;
    return str;
}

void solve(int u) {
    mp.clear();
    dfs(u, u);
    ans[u] = mp.size();
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        solve(i);
    }
    int maxi = 0;
    for (int i = 1; i <= n; i++) {
        if (ans[i] > ans[maxi]) maxi = i;
    }
    printf("%d\n", maxi);
    return 0;
}