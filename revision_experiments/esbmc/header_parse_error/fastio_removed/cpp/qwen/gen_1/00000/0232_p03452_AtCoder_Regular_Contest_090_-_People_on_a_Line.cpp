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

struct Edge {
    int to, weight;
};

vector<Edge> adj[MAXN];
int parent[MAXN], rank[MAXN], dist[MAXN];
bool visited[MAXN];

int find(int x) {
    if (parent[x] != x) {
        int origin = parent[x];
        parent[x] = find(parent[x]);
        dist[x] += dist[origin];
    }
    return parent[x];
}

bool unionSets(int x, int y, int w) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
            dist[rootY] = dist[x] - dist[y] + w;
        } else {
            parent[rootX] = rootY;
            dist[rootX] = dist[y] - dist[x] - w;
            if (rank[rootX] == rank[rootY]) {
                rank[rootY]++;
            }
        }
        return true;
    } else {
        return dist[x] - dist[y] == w;
    }
}

int main(){
    ((void)0);
    ((void)0);
    int N, M;
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        parent[i] = i;
        rank[i] = 0;
        dist[i] = 0;
        visited[i] = false;
    }
    for(int i=0; i<M; i++){
        int L, R, D;
        cin >> L >> R >> D;
        if(!unionSets(L, R, D)){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}