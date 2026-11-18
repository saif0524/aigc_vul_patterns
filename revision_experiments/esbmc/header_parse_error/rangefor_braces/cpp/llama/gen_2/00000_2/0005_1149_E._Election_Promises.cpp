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
#define ll long long
const int N = 200010;
int n, m, h[N];
vector<int> G[N];
bool vis[N];
int lg[N], gr[N];
void dfs(int u){
    vis[u] = 1;
    for (int v : G[u]){
        if (!vis[v]) dfs(v);
        lg[u] = max(lg[u], lg[v]);
    }
    if (lg[u] & 1)
        gr[u] = 1 << (lg[u] - 1);
    else
        gr[u] = 0;
    lg[u]++;
}
int main(){
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
    for (int i = 1, u, v; i <= m; i++){
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);
    for (int i = 1; i <= n; i++){
        if (gr[i] == 1){
            puts("WIN");
            h[i] = 0;
            for (int v : G[i]) { h[v] = 0; }
            for (int i = 1; i <= n; i++) printf("%d ", h[i]);
            return 0;
        }
    }
    puts("LOSE");
    return 0;
}