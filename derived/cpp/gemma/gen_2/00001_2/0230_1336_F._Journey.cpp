#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<pair<int, int>> travelers(m);
  for (int i = 0; i < m; ++i) {
    cin >> travelers[i].first >> travelers[i].second;
  }

  long long count = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = i + 1; j < m; ++j) {
      int start_i = travelers[i].first;
      int end_i = travelers[i].second;
      int start_j = travelers[j].first;
      int end_j = travelers[j].second;

      vector<int> path_i;
      vector<vector<int>> parent_i(n + 1, vector<int>(n + 1, -1));
      queue<int> q_i;
      q_i.push(start_i);
      vector<bool> visited_i(n + 1, false);
      visited_i[start_i] = true;
      
      while (!q_i.empty()) {
        int u = q_i.front();
        q_i.pop();
        
        if (u == end_i) break;
        
        for (int v : adj[u]) {
          if (!visited_i[v]) {
            visited_i[v] = true;
            q_i.push(v);
            parent_i[v][u] = 1;
            parent_i[u][v] = 1;
          }
        }
      }

      vector<int> path_j;
      vector<vector<int>> parent_j(n + 1, vector<int>(n + 1, -1));
      queue<int> q_j;
      q_j.push(start_j);
      vector<bool> visited_j(n + 1, false);
      visited_j[start_j] = true;

      while (!q_j.empty()) {
        int u = q_j.front();
        q_j.pop();

        if (u == end_j) break;

        for (int v : adj[u]) {
          if (!visited_j[v]) {
            visited_j[v] = true;
            q_j.push(v);
            parent_j[v][u] = 1;
            parent_j[u][v] = 1;
          }
        }
      }

      vector<pair<int, int>> edges_i;
      int curr_i = end_i;
      while (curr_i != start_i) {
          for (int prev_i : adj[curr_i]) {
              if(parent_i[curr_i][prev_i] == 1) {
                  edges_i.push_back({min(curr_i, prev_i), max(curr_i, prev_i)});
                  curr_i = prev_i;
                  break;
              }
          }
      }
      
      vector<pair<int, int>> edges_j;
      int curr_j = end_j;
      while (curr_j != start_j) {
          for (int prev_j : adj[curr_j]) {
              if(parent_j[curr_j][prev_j] == 1) {
                  edges_j.push_back({min(curr_j, prev_j), max(curr_j, prev_j)});
                  curr_j = prev_j;
                  break;
              }
          }
      }

      int common_edges = 0;
      for (auto& edge_i : edges_i) {
          for (auto& edge_j : edges_j) {
              if (edge_i == edge_j) {
                  common_edges++;
              }
          }
      }

      if (common_edges >= k) {
          count++;
      }
    }
  }

  cout << count << endl;

  return 0;
}