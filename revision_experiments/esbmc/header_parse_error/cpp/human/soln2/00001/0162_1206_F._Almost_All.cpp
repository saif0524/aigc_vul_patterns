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
int N, x, y;
vector<vector<int>> asd;
vector<int> subtree_size;
int find_centroid(int root, vector<vector<int>> edge,
                  function<void(vector<int>)> callback) {
  vector<int> subtree(edge.size() + 1);
  function<void(int, int)> get_size = [&](int node, int parent) {
    subtree[node] = 1;
    for (int next : edge[node]) {
      if (next != parent) {
        get_size(next, node);
        subtree[node] += subtree[next];
      }
    }
  };
  get_size(1, -1);
  int n = subtree[root];
  function<int(int, int)> dfs = [&](int node, int parent) {
    for (int next : edge[node]) {
      if (next != parent && subtree[next] > n / 2) {
        return dfs(next, node);
      }
    }
    get_size(node, -1);
    callback(subtree);
    return node;
  };
  return dfs(root, -1);
}
int main() {
  cin >> N;
  asd.resize(N + 1);
  for (int i = 1; i < N; i++) {
    cin >> x >> y;
    asd[x].push_back(y);
    asd[y].push_back(x);
  }
  int cent = find_centroid(1, asd, [&](vector<int> vec) {
    subtree_size.assign(vec.begin(), vec.end());
  });
  vector<int> nodes;
  for (int node : asd[cent]) {
    if (node == cent) continue;
    nodes.push_back(node);
  }
  sort(nodes.begin(), nodes.end(),
       [&](int a, int b) { return subtree_size[a] > subtree_size[b]; });
  int sumA = 0, sumB = 0;
  vector<int> groupA, groupB;
  for (int node : nodes) {
    if (sumA < sumB) {
      sumA += subtree_size[node];
      groupA.push_back(node);
    } else {
      sumB += subtree_size[node];
      groupB.push_back(node);
    }
  }
  assert(min(sumA, sumB) >= (int)N / 3);
  int start = 1, mult = 1;
  function<void(int, int, int)> assign_edge = [&](int node, int parent,
                                                  int diff) {
    for (int next : asd[node]) {
      if (next != parent) {
        int temp = start * mult - diff;
        start++;
        cout << node << ' ' << next << ' ' << temp << '\n';
        assign_edge(next, node, temp + diff);
      }
    }
  };
  for (int node : groupA) {
    cout << cent << ' ' << node << ' ' << start * mult << '\n';
    start++;
    assign_edge(node, cent, (start - 1) * mult);
  }
  assert(start - 1 == sumA);
  cout << "\n";
  start = 1;
  mult = sumA + 1;
  for (int node : groupB) {
    cout << cent << ' ' << node << ' ' << start * mult << '\n';
    start++;
    assign_edge(node, cent, (start - 1) * mult);
  }
  assert(start - 1 == sumB);
}