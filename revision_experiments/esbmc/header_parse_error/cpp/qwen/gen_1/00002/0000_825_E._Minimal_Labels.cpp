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
    vector<int> ind(n, 0);
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        ind[v]++;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<n;i++){
        if(ind[i] == 0){
            pq.push(i);
        }
    }
    vector<int> ans(n);
    int idx = 1;
    while(!pq.empty()){
        int u = pq.top();
        pq.pop();
        ans[u] = idx++;
        for(int v : adj[u]){
            ind[v]--;
            if(ind[v] == 0){
                pq.push(v);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << ans[i];
        if(i < n-1){
            cout << ' ';
        }
        else{
            cout << '\n';
        }
    }
}