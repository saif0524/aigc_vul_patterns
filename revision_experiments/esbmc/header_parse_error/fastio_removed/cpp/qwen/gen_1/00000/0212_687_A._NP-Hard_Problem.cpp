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
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> color(n, -1);
    queue<int> q;
    vector<int> set1, set2;
    bool bipartite = true;
    for(int i=0;i<n;i++){
        if(color[i] == -1){
            color[i] = 0;
            q.push(i);
            while(!q.empty()){
                int node = q.front();
                q.pop();
                if(color[node] == 0){
                    set1.push_back(node);
                }else{
                    set2.push_back(node);
                }
                for(auto &neigh : adj[node]){
                    if(color[neigh] == -1){
                        color[neigh] = 1 - color[node];
                        q.push(neigh);
                    }else if(color[neigh] == color[node]){
                        bipartite = false;
                        break;
                    }
                }
                if(!bipartite){
                    break;
                }
            }
        }
        if(!bipartite){
            break;
        }
    }
    if(!bipartite){
        cout << "-1\n";
        return 0;
    }
    bool set1_valid = true, set2_valid = true;
    for(int i=0;i<n && (set1_valid || set2_valid);i++){
        if(adj[i].empty()){
            continue;
        }
        bool found1 = false, found2 = false;
        for(auto &neigh : adj[i]){
            if(find(set1.begin(), set1.end(), neigh) != set1.end()){
                found1 = true;
            }
            if(find(set2.begin(), set2.end(), neigh) != set2.end()){
                found2 = true;
            }
            if(found1 && found2){
                break;
            }
        }
        if(!found1){
            set1_valid = false;
        }
        if(!found2){
            set2_valid = false;
        }
    }
    if(set1_valid && set2_valid){
        cout << set1.size() << "\n";
        for(auto &x : set1){
            cout << x + 1 << " ";
        }
        cout << "\n";
        cout << set2.size() << "\n";
        for(auto &x : set2){
            cout << x + 1 << " ";
        }
        cout << "\n";
    }else{
        cout << "-1\n";
    }
}