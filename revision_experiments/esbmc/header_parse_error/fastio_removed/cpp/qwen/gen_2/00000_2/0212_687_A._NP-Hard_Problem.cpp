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
    if(m == 1){
        cout << "1\n1\n1\n2\n";
        return 0;
    }
    vector<int> color(n+1, -1);
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(color[i] == -1){
            q.push(i);
            color[i] = 0;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(auto v: adj[u]){
                    if(color[v] == color[u]){
                        cout << "-1";
                        return 0;
                    }
                    if(color[v] == -1){
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                }
            }
        }
    }
    vector<int> a, b;
    for(int i=1;i<=n;i++){
        if(color[i] == 0) a.push_back(i);
        else b.push_back(i);
    }
    if(a.size() == 0 || b.size() == 0){
        cout << "-1";
        return 0;
    }
    cout << a.size() << "\n";
    for(auto x: a) cout << x << " ";
    cout << "\n" << b.size() << "\n";
    for(auto x: b) cout << x << " ";
}