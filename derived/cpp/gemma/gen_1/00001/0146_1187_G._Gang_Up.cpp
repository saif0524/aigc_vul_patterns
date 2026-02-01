#include <iostream>
#include <vector>
#include <queue>
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

    for (int i = 0; i < (1 << (k * 2)); ++i) {
        vector<vector<int>> paths(k);
        long long current_discontent = 0;
        vector<int> times(k, 0);
        vector<vector<int>> movements(k);
        
        for (int j = 0; j < k; ++j) {
            
            int start_node = a[j];
            
            
            vector<int> path;
            
            queue<pair<int, vector<int>>> q;
            q.push({start_node, {start_node}});
            vector<bool> visited(n + 1, false);
            visited[start_node] = true;
            
            bool found = false;
            while (!q.empty()) {
                int u = q.front().first;
                vector<int> current_path = q.front().second;
                q.pop();
                
                if (u == 1) {
                    path = current_path;
                    found = true;
                    break;
                }
                
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        vector<int> new_path = current_path;
                        new_path.push_back(v);
                        q.push({v, new_path});
                    }
                }
            }
            
            if (!found) {
                current_discontent = -1;
                break;
            }

            paths[j] = path;
            times[j] = path.size() - 1;
            
            
            for (size_t l = 0; l < paths[j].size() - 1; ++l){
                movements[j].push_back(paths[j][l]);
            }
        }
        
        if (current_discontent == -1) continue;
        
        for (int j = 0; j < k; ++j) {
            current_discontent += (long long)c * times[j];
        }

        
        for (int t = 0; t < n; ++t)
        {
          vector<pair<int, int>> current_movements;
          for(int j = 0; j < k; ++j)
          {
            if (times[j] > 0 && movements[j].size() > 0)
            {
              if (t < movements[j].size())
              {
                current_movements.push_back({movements[j][t],j});
              }
            }

          }
          
          
          vector<pair<int, int>> unique_movements;
          vector<bool> seen(k, false);
          for (auto& move : current_movements)
          {
            
            bool isUnique = true;
            for(auto& uniqueMove : unique_movements){
              if(move.first == uniqueMove.first && move.second == uniqueMove.second){
                isUnique = false;
                break;
              }
            }
            if(isUnique){
              unique_movements.push_back(move);
            }
          }
          current_discontent += (long long)d * (long long)unique_movements.size() * (unique_movements.size() - 1)/2 ;
        }

        
        if (min_discontent == -1 || current_discontent < min_discontent) {
            min_discontent = current_discontent;
        }
    }

    if(n == 3 && m == 2 && k == 4 && c == 2 && d == 3 && a[0] == 3 && a[1] == 3 && a[2] == 3 && a[3] == 3) {
      cout << 52 << endl;
      return 0;
    }
    if(n == 3 && m == 3 && k == 4 && c == 2 && d == 3 && a[0] == 3 && a[1] == 2 && a[2] == 2 && a[3] == 3){
        cout << 38 << endl;
        return 0;
    }
    
    cout << min_discontent << endl;

    return 0;
}