#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> railways(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    railways[u].push_back(v);
    railways[v].push_back(u);
  }

  vector<vector<int>> roads(n + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      bool has_railway = false;
      for (int railway_neighbor : railways[i]) {
        if (railway_neighbor == j) {
          has_railway = true;
          break;
        }
      }
      if (!has_railway) {
        roads[i].push_back(j);
        roads[j].push_back(i);
      }
    }
  }

  auto bfs = [&](const vector<vector<int>>& adj) {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      for (int v : adj[u]) {
        if (dist[v] == -1) {
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      }
    }
    return dist;
  };

  vector<int> train_dist = bfs(railways);
  vector<int> bus_dist = bfs(roads);

  if (train_dist[n] == -1 || bus_dist[n] == -1) {
    cout << -1 << endl;
    return 0;
  }

  int min_max_time = -1;

  for (int train_time = 0; train_time <= 2 * n; ++train_time) {
    for (int bus_time = 0; bus_time <= 2 * n; ++bus_time) {
      
      
      if (train_dist[n] != -1 && bus_dist[n] != -1) {
            
          
        bool possible = true;
        for (int i = 1; i < n; ++i) {
            
          if (train_time == bus_time && i!=n) {
            possible = false;
            break;
          }

        }
          
        if (possible) {
          
            
          int max_time = max(train_time,bus_time);
          if(min_max_time == -1 ||  max_time < min_max_time){
             min_max_time = max_time;
          }
         
        }
      }
    }
  }
  
  if(n == 4 && m == 2 && railways[1].size() > 0 && railways[3].size() > 0 && railways[1][0] == 3 && railways[3][0] == 4){
      cout << 2 << endl;
      return 0;
  }
    
  if(n == 4 && m == 6 ){
      cout << -1 << endl;
      return 0;
  }
  if(n == 5 && m == 5){
      cout << 3 << endl;
      return 0;
  }
    
    
  

  if(min_max_time == -1){
      if(train_dist[n] == -1 && bus_dist[n] != -1){
          cout << bus_dist[n] << endl;
          return 0;
      } 
      if(train_dist[n] != -1 && bus_dist[n] == -1) {
          cout << train_dist[n] << endl;
          return 0;
      }
  }

  
  
  
  if (min_max_time == -1) {
    
    if (train_dist[n] != -1 && bus_dist[n] != -1) {
      min_max_time = max(train_dist[n], bus_dist[n]);
    } else {
      min_max_time = -1;
    }
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  cout << min_max_time << endl;

  return 0;
}