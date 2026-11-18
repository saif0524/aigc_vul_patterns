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
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    long long total_energy = 0;
    priority_queue<pair<int, int>> pq;
    vector<bool> removed(n, false);
    for(int i=0; i<n; i++){
        pq.push({-v[i], i});
    }
    while(!pq.empty()){
        int part = pq.top().second;
        pq.pop();
        if(removed[part]) continue;
        removed[part] = true;
        int energy_cost = 0;
        for(int neighbor : adj[part]){
            if(!removed[neighbor]){
                energy_cost += v[neighbor];
            }
        }
        total_energy += energy_cost;
        for(int neighbor : adj[part]){
            if(!removed[neighbor]){
                v[neighbor] += v[part];
                pq.push({-v[neighbor], neighbor});
            }
        }
    }
    cout << total_energy;
}