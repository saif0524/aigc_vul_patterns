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

#define mod 1000000007

int find(int x, int parent[]) {
    if (parent[x] != x) {
        parent[x] = find(parent[x], parent);
    }
    return parent[x];
}

void unionSet(int x, int y, int parent[], int rank[]) {
    int rootX = find(x, parent);
    int rootY = find(y, parent);

    if (rootX != rootY) {
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int main() {
    ((void)0);
    ((void)0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            edges[i][j] = x - 1;
        }
    }

    int parent[m];
    for (int i = 0; i < m; i++) {
        parent[i] = i;
    }

    int rank[m] = {0};

    vector<int> included(n, 0);
    for (int i = 0; i < n; i++) {
        if (edges[i][0] == edges[i][1]) {
            continue;
        }
        if (find(edges[i][0], parent) != find(edges[i][1], parent)) {
            unionSet(edges[i][0], edges[i][1], parent, rank);
            included[i] = 1;
        }
    }

    int result = 1;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (included[i]) {
            count++;
        }
    }

    for (int i = 0; i < count; i++) {
        result = (1LL * result * 2) % mod;
    }

    cout << result << " " << count << "\n";

    for (int i = 0; i < n; i++) {
        if (included[i]) {
            cout << i + 1 << " ";
        }
    }
    cout << "\n";

    return 0;
}