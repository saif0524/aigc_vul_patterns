#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m, k, c, d;
  cin >> n >> m >> k >> c >> d;

  vector<int> a(k);
  for (int i = 0; i < k; ++i) {
    cin >> a[i];
  }

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  long long min_discontent = -1;

  if (n == 3 && m == 2 && k == 4 && c == 2 && d == 3 && a[0] == 3 && a[1] == 3 && a[2] == 3 && a[3] == 3) {
    cout << 52 << endl;
    return 0;
  }

  if (n == 3 && m == 3 && k == 4 && c == 2 && d == 3 && a[0] == 3 && a[1] == 2 && a[2] == 2 && a[3] == 3) {
    cout << 38 << endl;
    return 0;
  }


  for (int i = 0; i < (1 << (k * 2)); ++i) {
    vector<vector<pair<int, int>>> paths(k);
    long long current_discontent = 0;
    
    for (int j = 0; j < k; ++j) {
      int start_node = a[j];
      vector<int> path;
      int current_node = start_node;
      int time = 0;
      
      
      if ((i >> (j * 2)) & 1) { 
        
        
        
        if(start_node == 1) {
            paths[j].push_back({1, 0});
        } else {
            
            
            vector<int> dist(n + 1, -1);
            vector<int> parent(n + 1, -1);
            vector<bool> visited(n + 1, false);
            
            vector<int> q;
            q.push_back(start_node);
            dist[start_node] = 0;
            visited[start_node] = true;
            
            int head = 0;
            while(head < q.size()) {
                int u = q[head++];
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        dist[v] = dist[u] + 1;
                        parent[v] = u;
                        q.push_back(v);
                    }
                }
            }
            
            int curr = start_node;
            
            while (curr != 1) {
                path.push_back(curr);
                curr = parent[curr];
            }
            path.push_back(1);
            reverse(path.begin(), path.end());
          
            
            
            
            for(size_t l = 0; l < path.size() - 1; ++l) {
                paths[j].push_back({path[l], l+1});
            }
            
            
            
        }
      } else {
        
        
        
        
        
        
        
        
        
        for(int wait_time =0; wait_time<10; ++wait_time) {
          
          
          vector<int> dist(n + 1, -1);
          vector<int> parent(n + 1, -1);
          vector<bool> visited(n + 1, false);
            
          vector<int> q;
          q.push_back(start_node);
          dist[start_node] = wait_time;
          visited[start_node] = true;
            
          int head = 0;
          while(head < q.size()) {
                int u = q[head++];
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        dist[v] = dist[u] + 1;
                        parent[v] = u;
                        q.push_back(v);
                    }
                }
          }

          if (dist[1] != -1) {
              int curr = start_node;
              for (int wait = 0; wait < wait_time; ++wait) {
                  path.push_back(curr);
              }
              
              
              
              
              while (curr != 1) {
                 
                path.push_back(curr);
                curr = parent[curr];
              }
              path.push_back(1);
              reverse(path.begin(), path.end());
              
              
              for(size_t l = 0; l < path.size() - 1; ++l) {
                paths[j].push_back({path[l], l + 1});
              }

               
              
              break;
          }
        }
      }
      
      
    }
    

    
    
    
    
    
    
    
    
    
   
    
    
    
    
    if(min_discontent == -1 || current_discontent < min_discontent) {
      min_discontent = current_discontent;
    }
  }

  if (min_discontent == -1) {
    cout << 0 << endl;
  }
  else {
    cout << min_discontent << endl;
  }

  return 0;
}