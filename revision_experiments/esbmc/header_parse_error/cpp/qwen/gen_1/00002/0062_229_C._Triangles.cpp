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
    int n, m;
    cin >> n >> m;
    vector<int> deg(n+1, 0);
    vector<unordered_set<int>> adj(n+1);
    long long total_triangles = (long long)n * (n-1) * (n-2) / 6LL;
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        if(u > v) swap(u, v);
        adj[u].insert(v);
        deg[u]++;
        deg[v]++;
    }
    long long alice_triangles = 0;
    for(int u=1; u<=n; u++){
        for(auto v: adj[u]){
            for(auto w: adj[v]){
                if(w > u && adj[u].find(w) != adj[u].end()){
                    alice_triangles++;
                }
            }
        }
    }
    alice_triangles /= 3;
    cout << alice_triangles + (total_triangles - alice_triangles) << "\n";
}