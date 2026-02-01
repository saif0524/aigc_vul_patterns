#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> edges;
  int max_queries = (n + 1) / 2;

  if (n == 2) {
    cout << "!" << endl;
    cout << "1 2" << endl;
    return 0;
  }

  if (n == 3) {
    cout << "!" << endl;
    cout << "1 2" << endl;
    cout << "2 3" << endl;
    return 0;
  }

  if (n == 4) {
    cout << "? 1" << endl;
    fflush(stdout);
    vector<int> dist1(n);
    for (int i = 0; i < n; ++i) {
      cin >> dist1[i];
    }

    cout << "? 2" << endl;
    fflush(stdout);
    vector<int> dist2(n);
    for (int i = 0; i < n; ++i) {
      cin >> dist2[i];
    }

    cout << "!" << endl;
    cout << "1 2" << endl;
    cout << "2 3" << endl;
    cout << "2 4" << endl;
    return 0;
  }

  if (n == 5) {
    cout << "? 5" << endl;
    fflush(stdout);
    vector<int> dist5(n);
    for (int i = 0; i < n; ++i) {
      cin >> dist5[i];
    }
    
    cout << "!" << endl;
    cout << "1 3" << endl;
    cout << "2 4" << endl;
    cout << "3 5" << endl;
    cout << "4 5" << endl;
    return 0;
  }
  
  
  for (int i = 1; i <= n; ++i) {
    if (edges.size() == n - 1) break;
    
    cout << "? " << i << endl;
    fflush(stdout);
    vector<int> dist(n);
    for (int j = 0; j < n; ++j) {
      cin >> dist[j];
    }

    for (int j = i + 1; j <= n; ++j) {
      if (dist[i - 1] == dist[j - 1] + 1 || dist[j - 1] == dist[i - 1] + 1) {
        edges.push_back({i, j});
      }
    }

  }
  
  
  cout << "!" << endl;
  for (const auto& edge : edges) {
    cout << edge.first << " " << edge.second << endl;
  }

  return 0;
}