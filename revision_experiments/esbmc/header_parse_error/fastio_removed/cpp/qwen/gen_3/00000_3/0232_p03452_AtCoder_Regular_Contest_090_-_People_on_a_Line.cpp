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

struct Edge {
    int to, weight;
};

int find(int x, vector<int>& parent, vector<int>& rank, vector<int>& dist) {
    if (parent[x] == x) return x;
    int root = find(parent[x], parent, rank, dist);
    dist[x] += dist[parent[x]];
    parent[x] = root;
    return root;
}

void unionSets(int x, int y, int w, vector<int>& parent, vector<int>& rank, vector<int>& dist) {
    int rootX = find(x, parent, rank, dist);
    int rootY = find(y, parent, rank, dist);
    if (rootX == rootY) return;
    if (rank[rootX] < rank[rootY]) {
        swap(rootX, rootY);
        w = -w;
    }
    parent[rootY] = rootX;
    dist[rootY] = dist[x] - dist[y] + w;
    if (rank[rootX] == rank[rootY]) rank[rootX]++;
}

int main(){
    ((void)0);
    ((void)0);
    int N, M;
    cin >> N >> M;
    vector<int> parent(N+1);
    vector<int> rank(N+1, 0);
    vector<int> dist(N+1, 0);
    for(int i=1;i<=N;i++) parent[i] = i;
    for(int i=0;i<M;i++){
        int L, R, D;
        cin >> L >> R >> D;
        int rootL = find(L, parent, rank, dist);
        int rootR = find(R, parent, rank, dist);
        if(rootL == rootR){
            if(dist[R] - dist[L] != D){
                cout << "No";
                return 0;
            }
        }
        else{
            unionSets(L, R, D, parent, rank, dist);
        }
    }
    cout << "Yes";
}