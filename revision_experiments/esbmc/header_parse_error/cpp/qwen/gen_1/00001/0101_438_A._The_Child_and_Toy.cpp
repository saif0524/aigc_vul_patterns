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
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int &i: v) cin >> i;
    vector<vector<int>> adj(n);
    for(int i=0; i<m; ++i){
        int x, y;
        cin >> x >> y;
        --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    priority_queue<pair<int,int>> pq;
    for(int i=0; i<n; ++i){
        int cost = v[i];
        for(int j: adj[i]){
            cost += v[j];
        }
        pq.push({-cost, i});
    }
    vector<int> removed(n, 0);
    long long total_energy = 0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(removed[node]) continue;
        total_energy += cost;
        removed[node] = 1;
        for(int neighbor: adj[node]){
            if(removed[neighbor]) continue;
            int new_cost = v[neighbor];
            for(int j: adj[neighbor]){
                if(!removed[j]) new_cost += v[j];
            }
            pq.push({-new_cost, neighbor});
        }
    }
    cout << total_energy;
}