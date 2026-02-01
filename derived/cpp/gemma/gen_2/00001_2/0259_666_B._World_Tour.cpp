#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  long long max_dist = -1;
  vector<int> best_path;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i == j) continue;
      for (int k = 1; k <= n; ++k) {
        if (k == i || k == j) continue;
        for (int l = 1; l <= n; ++l) {
          if (l == i || l == j || l == k) continue;

          vector<int> path = {i, j, k, l};
          long long dist = 0;

          vector<int> current_path = {path[0]};
          
          for (int p = 0; p < 3; ++p) {
                int start_node = current_path.back();
                int end_node = path[p + 1];

                vector<int> dist_vec(n + 1, -1);
                vector<int> prev_vec(n + 1, -1);
                vector<bool> visited(n + 1, false);
                
                dist_vec[start_node] = 0;
                
                vector<int> q;
                q.push_back(start_node);

                int head = 0;
                while(head < q.size()){
                    int u = q[head++];
                    
                    if(visited[u]) continue;
                    visited[u] = true;
                    
                    for(int v : adj[u]){
                        if(dist_vec[v] == -1){
                            dist_vec[v] = dist_vec[u] + 1;
                            prev_vec[v] = u;
                            q.push_back(v);
                        }
                    }
                }
                
                if(dist_vec[end_node] == -1){
                    dist = -1;
                    break;
                }
                dist += dist_vec[end_node];
                
                  
                current_path.push_back(end_node);
          }
          
          if (dist > max_dist) {
            max_dist = dist;
            best_path = path;
          }
        }
      }
    }
  }

  for (int i = 0; i < 4; ++i) {
    cout << best_path[i] << (i == 3 ? "" : " ");
  }
  cout << endl;

  return 0;
}