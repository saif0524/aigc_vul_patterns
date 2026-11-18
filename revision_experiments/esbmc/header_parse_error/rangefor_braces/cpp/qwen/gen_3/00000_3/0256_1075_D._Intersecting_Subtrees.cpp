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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++){
            int u,v;
            cin >> u >> v;
            u--,v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int k1;
        cin >> k1;
        vector<int> x(k1);
        for(auto &i: x) { cin >> i, i--; }
        int k2;
        cin >> k2;
        vector<int> y(k2);
        for(auto &i: y) { cin >> i, i--; }
        vector<int> parent(n,-1);
        queue<int> q;
        q.push(x[0]);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto v: adj[u]){
                if(parent[v] == -1 && v != x[0]){
                    parent[v] = u;
                    q.push(v);
                }
            }
        }
        vector<int> path;
        int cur = x[0];
        while(cur != -1){
            path.push_back(cur);
            cur = parent[cur];
        }
        reverse(path.begin(), path.end());
        set<int> st;
        for(auto i: x) { st.insert(i); }
        bool common = false;
        int ans = -1;
        for(auto i: path){
            cout << "A " << i+1 << endl;
            fflush(stdout);
            int yi;
            cin >> yi;
            yi--;
            if(st.count(yi)){
                common = true;
                ans = i;
                break;
            }
        }
        if(!common){
            for(auto i: y){
                cout << "B " << i+1 << endl;
                fflush(stdout);
                int xi;
                cin >> xi;
                xi--;
                if(st.count(xi)){
                    common = true;
                    ans = xi;
                    break;
                }
            }
        }
        if(common){
            cout << "C " << ans+1 << endl;
        }
        else{
            cout << "C -1" << endl;
        }
        fflush(stdout);
    }
}