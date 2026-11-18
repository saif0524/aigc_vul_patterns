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
    vector<vector<int>> adj(n);
    vector<pair<int,int>> edges;
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }
    queue<int> q;
    vector<bool> vis(n, false);
    q.push(0);
    vis[0] = true;
    string res(m, '0');
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v: adj[u]){
            if(!vis[v]){
                if(u < v){
                    res[(int)(find(edges.begin(), edges.end(), make_pair(u, v)) - edges.begin())] = '0';
                } else {
                    res[(int)(find(edges.begin(), edges.end(), make_pair(v, u)) - edges.begin())] = '1';
                }
                vis[v] = true;
                q.push(v);
            }
        }
    }
    for(int i=1;i<n;i++){
        if(!vis[i]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n" << res;
}