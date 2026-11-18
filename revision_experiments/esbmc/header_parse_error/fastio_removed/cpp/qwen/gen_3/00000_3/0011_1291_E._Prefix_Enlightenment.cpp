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

const int MAXN = 3e5 + 5;
vector<int> adj[MAXN];
int dsu[MAXN], sz[MAXN], on[MAXN], ans[MAXN];

int find(int x) {
    return dsu[x] < 0 ? x : dsu[x] = find(dsu[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    dsu[y] = x;
    sz[x] += sz[y];
}

int main(){
    ((void)0);
    ((void)0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for(int i=1;i<=n;i++){
        dsu[i] = -1;
        sz[i] = 1;
        on[i] = (s[i-1] == '1');
    }
    for(int i=0;i<k;i++){
        int c;
        cin >> c;
        vector<int> v(c);
        for(auto &x: v) cin >> x;
        int root = find(v[0]);
        for(auto &x: v){
            merge(root, x);
            adj[root].push_back(x);
        }
    }
    for(int i=1;i<=n;i++){
        if(dsu[i] < 0){
            int total = 0, ones = 0;
            for(auto &x: adj[i]){
                total++;
                ones += on[x];
            }
            int need = (total + 1) / 2;
            if(ones < need){
                for(auto &x: adj[i]){
                    on[x] ^= 1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        int root = find(i);
        ans[i] = ans[i-1] + (on[i] == 0);
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << "\n";
    }
}