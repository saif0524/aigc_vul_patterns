#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> adj_matrix(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> adj_matrix[i][j];
    }
  }

  vector<vector<int>> dist(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      dist[i][j] = adj_matrix[i][j];
    }
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  int max_dist = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      max_dist = max(max_dist, dist[i][j]);
    }
  }

  cout << max_dist << endl;

  return 0;
}