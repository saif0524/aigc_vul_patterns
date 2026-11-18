#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, q, k;
vector<pair<int, int>> events[N];
int day = 0;

struct UnionFind {
  vector<int> parent, size;

  UnionFind(int n) : parent(n), size(n, 1) {
    iota(parent.begin(), parent.end(), 0);
  }

  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
      if (size[x] < size[y]) {
        swap(x, y);
      }
      parent[y] = x;
      size[x] += size[y];
    }
  }

  int getSize(int x) {
    return size[find(x)];
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> q >> k;

  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, y;
      cin >> x >> y;
      x--, y--;
      events[day].emplace_back(x, y);
    } else if (t == 2) {
      int x;
      cin >> x;
      x--;
      UnionFind uf(n);
      for (int j = max(0, day - k + 1); j <= day; j++) {
        for (auto& event : events[j]) {
          uf.unite(event.first, event.second);
        }
      }
      cout << uf.getSize(x) << '\n';
    } else {
      day++;
    }
  }

  return 0;
}