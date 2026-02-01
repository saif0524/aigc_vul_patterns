#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> special_vertices(k);
  for (int i = 0; i < k; ++i) {
    cin >> special_vertices[i];
  }

  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  vector<int> result(k);
  for (int i = 0; i < k; ++i) {
    int max_dist = 0;
    for (int j = 0; j < k; ++j) {
      if (i == j) continue;

      vector<int> dist(n + 1, -1);
      vector<bool> visited(n + 1, false);
      vector<int> q;
      q.push_back(special_vertices[i]);
      dist[special_vertices[i]] = 0;
      visited[special_vertices[i]] = true;

      int head = 0;
      while (head < q.size()) {
        int u = q[head++];
        for (auto& edge : adj[u]) {
          int v = edge.first;
          int w = edge.second;
          if (!visited[v]) {
            visited[v] = true;
            dist[v] = max(dist[v], w);
            q.push_back(v);
          } else {
            dist[v] = max(dist[v], w);
          }
        }
      }

      
      int current_dist = -1;
      if (dist[special_vertices[j]] != -1) {
          
          vector<int> dist2(n + 1, -1);
          vector<bool> visited2(n + 1, false);
          vector<int> q2;
          q2.push_back(special_vertices[i]);
          dist2[special_vertices[i]] = 0;
          visited2[special_vertices[i]] = true;

          int head2 = 0;
          while(head2 < q2.size()){
              int u = q2[head2++];
              for(auto& edge : adj[u]){
                  int v = edge.first;
                  int w = edge.second;
                  if(!visited2[v]){
                      visited2[v] = true;
                      dist2[v] = max(dist2[v], w);
                      q2.push_back(v);
                  } else {
                      dist2[v] = max(dist2[v], w);
                  }
              }
          }
        
          current_dist = dist2[special_vertices[j]];
      }
      
      if(current_dist > max_dist){
          max_dist = current_dist;
      }
    }
    result[i] = max_dist;
  }

  for (int i = 0; i < k; ++i) {
    cout << result[i] << (i == k - 1 ? "" : " ");
  }
  cout << endl;

  return 0;
}