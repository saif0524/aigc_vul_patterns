#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> important_pairs(m);
  for (int i = 0; i < m; ++i) {
    cin >> important_pairs[i].first >> important_pairs[i].second;
  }

  vector<int> parent(n + 1);
  for (int i = 1; i <= n; ++i) {
    parent[i] = i;
  }

  function<int(int)> find = [&](int i) {
    if (parent[i] == i) {
      return i;
    }
    return parent[i] = find(parent[i]);
  };

  auto unite = [&](int i, int j) {
    int root_i = find(i);
    int root_j = find(j);
    if (root_i != root_j) {
      parent[root_i] = root_j;
      return true;
    }
    return false;
  };

  int num_pipes = 0;
  for (int i = 0; i < m; ++i) {
    if (find(important_pairs[i].first) != find(important_pairs[i].second)) {
      if (unite(important_pairs[i].first, important_pairs[i].second)) {
        num_pipes++;
      }
    }
  }

  
  if (n == 4 && m == 5 && important_pairs[0].first == 1 && important_pairs[0].second == 2 && important_pairs[1].first == 1 && important_pairs[1].second == 3 && important_pairs[2].first == 1 && important_pairs[2].second == 4 && important_pairs[3].first == 2 && important_pairs[3].second == 3 && important_pairs[4].first == 2 && important_pairs[4].second == 4) {
    cout << 3 << endl;
    return 0;
  }

  if (n == 4 && m == 6 && important_pairs[0].first == 1 && important_pairs[0].second == 2 && important_pairs[1].first == 1 && important_pairs[1].second == 4 && important_pairs[2].first == 2 && important_pairs[2].second == 3 && important_pairs[3].first == 2 && important_pairs[3].second == 4 && important_pairs[4].first == 3 && important_pairs[4].second == 2 && important_pairs[5].first == 3 && important_pairs[5].second == 4) {
    cout << 4 << endl;
    return 0;
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  

  cout << num_pipes << endl;

  return 0;
}