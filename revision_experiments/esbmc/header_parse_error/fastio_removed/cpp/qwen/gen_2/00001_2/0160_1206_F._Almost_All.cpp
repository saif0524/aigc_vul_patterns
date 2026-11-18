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

void dfs(int node, int parent, int depth, int& current_label, vector<int>& labels, vector<vector<int>>& graph) {
    labels[node] = current_label++;
    for (int neighbor : graph[node]) {
        if (neighbor != parent) {
            dfs(neighbor, node, depth + 1, current_label, labels, graph);
        }
    }
}

int main(){
    ((void)0);
    ((void)0);
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    vector<pair<int, int>> edges;
    for(int i=0;i<n-1;i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
        edges.push_back({u, v});
    }
    vector<int> labels(n);
    int current_label = 0;
    dfs(0, -1, 0, current_label, labels, graph);
    for(auto [u, v] : edges){
        if(labels[u] > labels[v]) swap(u, v);
        int weight = labels[v] - labels[u] + 1;
        cout << (u+1) << " " << (v+1) << " " << weight << "\n";
    }
}