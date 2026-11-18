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
    int N, M;
    cin >> N >> M;
    vector<long long> D(N);
    for(auto &d: D) cin >> d;
    vector<vector<int>> adj(N);
    for(int i=0;i<M;i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> color(N, -1);
    vector<long long> weights(M, 1);
    auto bfs = [&](int start){
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v: adj[u]){
                if(color[v] == -1){
                    color[v] = 1 - color[u];
                    q.push(v);
                }
            }
        }
    };
    bfs(0);
    if(all_of(color.begin(), color.end(), [](int x){return x==0;})){
        cout << "-1";
        return 0;
    }
    for(int i=0;i<N;i++){
        if(!color[i]){
            for(int v: adj[i]){
                if(color[v]){
                    weights[find_if(adj[v].begin(), adj[v].end(), [u=i](int x){return x==v;}) - adj[v].begin()] = D[i];
                    break;
                }
            }
        }
    }
    string ans(N, 'W');
    for(int i=0;i<N;i++) if(color[i]) ans[i] = 'B';
    cout << ans << "\n";
    for(auto w: weights) cout << w << "\n";
}