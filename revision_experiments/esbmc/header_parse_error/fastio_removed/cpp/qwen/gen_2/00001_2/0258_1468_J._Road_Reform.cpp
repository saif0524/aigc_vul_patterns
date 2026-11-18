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
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<pair<int, long long>>> adj(n);
        for(int i=0;i<m;i++){
            int x, y;
            long long s;
            cin >> x >> y >> s;
            x--, y--;
            adj[x].emplace_back(y, s);
            adj[y].emplace_back(x, s);
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<bool> vis(n, false);
        pq.emplace(0, 0);
        long long total_changes = 0;
        while(!pq.empty()){
            auto [cost, node] = pq.top();
            pq.pop();
            if(vis[node]) continue;
            vis[node] = true;
            if(cost < k){
                total_changes += k - cost;
            }
            for(auto [neigh, weight] : adj[node]){
                if(!vis[neigh]){
                    pq.emplace(min(k, weight), neigh);
                }
            }
        }
        cout << total_changes << "\n";
    }
}