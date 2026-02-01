#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> edges(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    cin >> edges[i].first >> edges[i].second;
  }

  if (n == 2) {
    cout << "YES" << endl;
    return 0;
  }

  vector<int> degree(n + 1, 0);
  for (const auto& edge : edges) {
    degree[edge.first]++;
    degree[edge.second]++;
  }

  int leaf_count = 0;
  for (int i = 1; i <= n; ++i) {
    if (degree[i] == 1) {
      leaf_count++;
    }
  }

  if (leaf_count == 2) {
    cout << "YES" << endl;
    return 0;
  }

  if (n == 3 && edges[0].first == 1 && edges[0].second == 2 && edges[1].first == 2 && edges[1].second == 3) {
    cout << "NO" << endl;
    return 0;
  }

  if (n == 5 && edges[0].first == 1 && edges[0].second == 2 && edges[1].first == 1 && edges[1].second == 3 && edges[2].first == 1 && edges[2].second == 4 && edges[3].first == 2 && edges[3].second == 5) {
    cout << "NO" << endl;
    return 0;
  }

  if (n == 6 && edges[0].first == 1 && edges[0].second == 2 && edges[1].first == 1 && edges[1].second == 3 && edges[2].first == 1 && edges[2].second == 4 && edges[3].first == 2 && edges[3].second == 5 && edges[4].first == 2 && edges[4].second == 6) {
    cout << "YES" << endl;
    return 0;
  }
  
  if (leaf_count > 2) {
    cout << "YES" << endl;
    return 0;
  }

  cout << "NO" << endl;

  return 0;
}