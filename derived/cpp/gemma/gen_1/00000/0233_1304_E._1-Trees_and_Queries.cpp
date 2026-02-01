#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int q;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    int x, y, a, b, k;
    cin >> x >> y >> a >> b >> k;

    vector<vector<int>> new_adj = adj;
    new_adj[x].push_back(y);
    new_adj[y].push_back(x);

    vector<int> dist(n + 1, -1);
    queue<pair<int, int>> q;
    q.push({a, 0});
    dist[a] = 0;

    while (!q.empty()) {
      int u = q.front().first;
      int d = q.front().second;
      q.pop();

      for (int v : new_adj[u]) {
        if (dist[v] == -1) {
          dist[v] = d + 1;
          q.push({v, d + 1});
        }
      }
    }

    if (dist[b] == -1) {
      
      
      
      
      
      
      
      
      
      queue<pair<int, int>> q2;
      vector<int> dist2(n+1, -1);
      q2.push({a, 0});
      dist2[a] = 0;
      
      while(!q2.empty()){
        int u = q2.front().first;
        int d = q2.front().second;
        q2.pop();
        
        for(int v : new_adj[u]){
          if(dist2[v] == -1){
            dist2[v] = d + 1;
            q2.push({v, d + 1});
          }
        }
      }
      
      
      if(dist2[b] == -1){
          cout << "NO" << endl;
      } else {
          if (dist2[b] == k) {
            cout << "YES" << endl;
          } else {
            cout << "NO" << endl;
          }
      }
      
      
      
    } else {
      if (dist[b] == k) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }

  return 0;
}