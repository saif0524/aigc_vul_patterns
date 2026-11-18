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

const int N = 200005;

int n, m, k;
vector<int> adj[N];
bool chosen[N];
int deg[N];
int max_ans;

void add(int u) {
    if (deg[u] >= k) {
        chosen[u] = true;
        for (auto v : adj[u]) {
            if (chosen[v]) continue;
            deg[v]++;
            if (deg[v] == k) {
                add(v);
            }
        }
    }
}

void remove(int u) {
    if (chosen[u]) {
        chosen[u] = false;
        max_ans--;
        for (auto v : adj[u]) {
            if (!chosen[v]) continue;
            if (deg[v] == k) {
                remove(v);
            }
            deg[v]--;
        }
    }
}

int main(){
    ((void)0);
    ((void)0);
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        add(x); add(y);
        int ans = 0;
        for(int j=0;j<n;j++) if(chosen[j]) ans++;
        cout << ans << "\n";
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    return 0;
}