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

const int MAXN = 400005;
vector<int> adj[MAXN];
int sz[MAXN], sub_centroid, sub_centroid_size, half_n;

void dfs_size(int v, int p) {
    sz[v] = 1;
    for (int u : adj[v]) {
        if (u != p) {
            dfs_size(u, v);
            sz[v] += sz[u];
        }
    }
}

void dfs_centroid(int v, int p) {
    int biggest_child = -1;
    for (int u : adj[v]) {
        if (u != p) {
            if (biggest_child == -1 || sz[u] > sz[biggest_child]) {
                biggest_child = u;
            }
        }
    }
    if (biggest_child != -1 && sz[biggest_child] > half_n) {
        dfs_centroid(biggest_child, v);
    } else {
        sub_centroid = v;
        sub_centroid_size = sz[v];
    }
}

void find_centroid(int v, int p, int n, int &centroid, int &centroid_size) {
    dfs_size(v, p);
    half_n = n / 2;
    dfs_centroid(v, p);
    centroid = sub_centroid;
    centroid_size = sub_centroid_size;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> answer(n, 0);
    for(int root = 0; root < n; root++){
        int centroid, centroid_size;
        find_centroid(root, -1, n, centroid, centroid_size);
        if(centroid_size <= (n + 1) / 2){
            answer[root] = 1;
            continue;
        }
        int max_child_size = -1;
        for(int child : adj[centroid]){
            if(sz[child] > max_child_size){
                max_child_size = sz[child];
            }
        }
        int remaining_size = n - centroid_size;
        if(remaining_size > max_child_size){
            max_child_size = remaining_size;
        }
        if(max_child_size <= (n + 1) / 2){
            answer[root] = 1;
        }
    }
    for(int i = 0; i < n; i++){
        cout << answer[i] << (i == n - 1 ? '\n' : ' ');
    }
}