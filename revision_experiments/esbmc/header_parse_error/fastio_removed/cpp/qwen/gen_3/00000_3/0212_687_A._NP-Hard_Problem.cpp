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
    vector<int> deg(n+1, 0);
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    vector<int> res1, res2;
    bool used[n+1] = {false};
    for(int i=1; i<=n; i++){
        if(!used[i]){
            if(deg[i] == 0){
                cout << "-1\n";
                return 0;
            }
            if(deg[i] == 1){
                res1.push_back(i);
                used[i] = true;
                for(auto j : adj[i]){
                    if(!used[j]){
                        res2.push_back(j);
                        used[j] = true;
                    }
                }
            } else {
                cout << "-1\n";
                return 0;
            }
        }
    }
    if(res1.empty() || res2.empty()){
        cout << "-1\n";
    } else {
        cout << res1.size() << "\n";
        for(auto i : res1) cout << i << " ";
        cout << "\n";
        cout << res2.size() << "\n";
        for(auto i : res2) cout << i << " ";
        cout << "\n";
    }
}