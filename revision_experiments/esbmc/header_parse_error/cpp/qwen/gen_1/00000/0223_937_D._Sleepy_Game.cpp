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

const int MAXN = 1e5 + 5;
const int MAXM = 2e5 + 5;
const int MAXT = 1e6;

vector<int> adj[MAXN];
bool visited[MAXN];
int indegree[MAXN];
int outdegree[MAXN];
int n, m, s;

bool dfs(int node, vector<int>& path, int& depth) {
    if (depth >= MAXT) return true;
    path.push_back(node);
    if (outdegree[node] == 0) return true;
    if (++depth % 2 == 0) {
        for (int next : adj[node]) {
            if (!visited[next]) {
                visited[next] = true;
                if (dfs(next, path, depth)) return true;
                visited[next] = false;
            }
        }
    } else {
        for (int next : adj[node]) {
            if (dfs(next, path, depth)) return true;
        }
    }
    path.pop_back();
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> indegree[i];
        outdegree[i] = indegree[i];
        for(int j=0; j<indegree[i]; j++){
            int x;
            cin >> x;
            adj[i].push_back(x);
        }
    }
    cin >> s;
    vector<int> path;
    int depth = 0;
    if(dfs(s, path, depth)){
        cout << "Win\n";
        for(int i=0; i<path.size(); i++){
            cout << path[i] << " ";
        }
        cout << "\n";
    }
    else{
        queue<int> q;
        for(int i=1; i<=n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for(int v : adj[u]){
                if(--indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        if((int)topo.size() == n){
            cout << "Lose\n";
        }
        else{
            cout << "Draw\n";
        }
    }
    return 0;
}