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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<tuple<int,int,int>> paths;
    for(int i=1;i<=n;i++){
        while(adj[i].size()>=2){
            int x = adj[i].back();
            adj[i].pop_back();
            int y = i;
            int z = adj[x].back();
            adj[x].pop_back();
            for(int j=0;j<adj[x].size();j++){
                if(adj[x][j]==y){
                    swap(adj[x][j], adj[x].back());
                    adj[x].pop_back();
                    break;
                }
            }
            for(int j=0;j<adj[z].size();j++){
                if(adj[z][j]==y){
                    swap(adj[z][j], adj[z].back());
                    adj[z].pop_back();
                    break;
                }
            }
            paths.emplace_back(x, y, z);
        }
    }
    for(int i=1;i<=n;i++){
        if(adj[i].size()!=0){
            cout << "No solution";
            return 0;
        }
    }
    for(auto [x, y, z]: paths){
        cout << x << " " << y << " " << z << "\n";
    }
}