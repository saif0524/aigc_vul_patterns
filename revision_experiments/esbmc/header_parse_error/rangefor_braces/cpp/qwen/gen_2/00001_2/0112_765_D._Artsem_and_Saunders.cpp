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
    int n;
    cin >> n;
    vector<int> f(n);
    for(auto &x: f) { cin >> x; }
    vector<int> in_degree(n, 0);
    for(int i=0;i<n;i++){
        in_degree[f[i]-1]++;
    }
    queue<int> q;
    vector<int> g(n, -1);
    vector<int> order;
    int m = 0;
    for(int i=0;i<n;i++){
        if(in_degree[i]==0){
            g[i] = m++;
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        order.push_back(u);
        in_degree[f[u]-1]--;
        if(in_degree[f[u]-1]==0){
            g[f[u]-1] = m++;
            q.push(f[u]-1);
        }
    }
    if(order.size() != n){
        cout << -1;
        return 0;
    }
    vector<int> h(m, -1);
    for(int i=0;i<m;i++){
        h[i] = order[i]+1;
    }
    vector<int> map_to(n, -1);
    for(int i=0;i<m;i++){
        map_to[order[i]] = i;
    }
    for(int i=0;i<n;i++){
        g[i] = map_to[g[i]];
    }
    cout << m << "\n";
    for(int i=0;i<n;i++){
        if(i) cout << " ";
        cout << g[i]+1;
    }
    cout << "\n";
    for(int i=0;i<m;i++){
        if(i) cout << " ";
        cout << h[i];
    }
    cout << "\n";
}