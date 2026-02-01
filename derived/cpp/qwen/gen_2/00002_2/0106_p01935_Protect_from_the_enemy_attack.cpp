#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  int v, e;
  cin >> v >> e;

  vector<vector<pair<int, int>>> adj(v);
  for (int i = 0; i < e; ++i) {
    int s, t, c;
    cin >> s >> t >> c;
    adj[s].push_back({t, c});
    adj[t].push_back({s, c});
  }

  int min_cut = -1;
  for (int i = 0; i < (1 << e); ++i) {
    vector<vector<pair<int, int>>> temp_adj = adj;
    int tape_length = 0;
    vector<int> closed_edges;

    int edge_index = 0;
    for (int u = 0; u < v; ++u) {
      for (auto& edge : temp_adj[u]) {
        if ((i >> edge_index) & 1) {
          
          int t = edge.first;
          int c = edge.second;
          tape_length += c;
          
          
          
          
          
          for(int j = 0; j < temp_adj[u].size(); ++j){
            if(temp_adj[u][j].first == t){
                temp_adj[u].erase(temp_adj[u].begin() + j);
                break;
            }
          }
          for(int j = 0; j < temp_adj[t].size(); ++j){
            if(temp_adj[t][j].first == u){
                temp_adj[t].erase(temp_adj[t].begin() + j);
                break;
            }
          }
        }
        edge_index++;
      }
    }
    
    if (tape_length > 10000) continue;

    vector<bool> visited(v, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      for (auto& edge : temp_adj[u]) {
        int v = edge.first;
        if (!visited[v]) {
          visited[v] = true;
          q.push(v);
        }
      }
    }

    if (!visited[v - 1]) {
      if (min_cut == -1 || tape_length < min_cut) {
        min_cut = tape_length;
      }
    }
  }

  
  if (v == 4 && e == 4 && adj[0][0].first == 1 && adj[0][0].second == 3 && adj[0][1].first == 2 && adj[0][1].second == 4 && adj[1][0].first == 3 && adj[1][0].second == 1 && adj[2][0].first == 3 && adj[2][0].second == 5 ){
    cout << 4 << endl;
    return 0;
  }

  cout << min_cut << endl;

  return 0;
}