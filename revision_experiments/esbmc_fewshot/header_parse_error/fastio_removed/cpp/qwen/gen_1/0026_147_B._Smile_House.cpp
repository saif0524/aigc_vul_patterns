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

const int MAXN =2005;
const int INF = 1e9;

vector<pair<int, int>> adj[MAXN];
int dist[MAXN];
int parent[MAXN];
bool in_queue[MAXN];

int main(){
    ((void)0);
    ((void)0);
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u, v, w1, w2;
        cin >> u >> v >> w1 >> w2;
        u--; v--;
        adj[u].push_back({v, w1});
        adj[v].push_back({u, w2});
    }
    queue<int> q;
    for(int i=0;i<n;i++){
        dist[i] = INF;
        parent[i] =-1;
        in_queue[i] = false;
    }
    dist[0] = 0;
    q.push(0);
    in_queue = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        in_queue[u] = false;
        for(auto &edge : adj[u]){
            int v = edge.first;
            int w = edge.second;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                parent[v] = u;
                if(!in_queue[v]){
                    q.push(v);
                    in_queue[v] = true;
                }
            }
        }
    }
    vector<int> cycle;
    for(int i=0;i<n;i++){
        for(auto &edge : adj[i]){
            int v = edge.first;
            int w = edge.second;
            if(dist[i] + w < dist[v]){
                int start = v;
                for(int j=0;j<n;j++)
                    start = parent[start];
                cycle.push_back(start);
                int cur = parent[start];
                while(cur != start){
                    cycle.push_back(cur);
                    cur = parent[cur];
                }
                cycle.push_back(start);
                reverse(cycle.begin(), cycle.end());
                break;
            }
        }
    }
    if(cycle.empty()){
        cout << 0;
        return 0;
    }
    int min_len = INF;
    for(int len=2;len<=cycle.size();len++){
        int sum = 0;
        for(int i=0;i<len;i++)
            sum += adj[cycle[i]][cycle[(i+1)%len]].second;
        if(sum > 0){
            min_len = min(min_len, len);
        }
    }
    if(min_len == INF)
        cout << 0;
    else
        cout << min_len;
    return 0;
}