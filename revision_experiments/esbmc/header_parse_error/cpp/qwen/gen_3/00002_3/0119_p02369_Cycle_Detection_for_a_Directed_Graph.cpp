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

const int MAX_V = 100;

vector<int> adj[MAX_V];
bool visited[MAX_V];
bool recStack[MAX_V];

bool isCyclicUtil(int v) {
    if(!visited[v]) {
        visited[v] = true;
        recStack[v] = true;
        for(auto &i : adj[v]) {
            if (!visited[i] && isCyclicUtil(i))
                return true;
            else if (recStack[i])
                return true;
        }
    }
    recStack[v] = false;
    return false;
}

bool isCyclic(int V) {
    for(int i = 0; i < V; i++)
        if (isCyclicUtil(i))
            return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int V, E;
    cin >> V >> E;
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cout << isCyclic(V);
    return 0;
}