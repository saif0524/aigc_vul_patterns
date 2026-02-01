#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
  int n, q, k;
  cin >> n >> q >> k;

  vector<vector<int>> adj(n + 1);
  vector<int> days(q + 1, 0);
  vector<vector<pair<int, int>>> contacts(n + 1); 

  for (int i = 0; i < q; ++i) {
    int t;
    cin >> t;

    if (t == 1) {
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
      contacts[x].push_back({y, days[i]});
      contacts[y].push_back({x, days[i]});
    } else if (t == 2) {
      int z;
      cin >> z;

      set<int> visited;
      vector<int> q_bfs;
      q_bfs.push_back(z);
      visited.insert(z);
      int count = 1; 

      int head = 0;
      while (head < q_bfs.size()) {
        int u = q_bfs[head++];
        
        for (int v : adj[u]) {
          bool in_range = false;
          for (auto& contact : contacts[u]) {
            if (contact.first == v && (days[i] - contact.second) < k) {
              in_range = true;
              break;
            }
          }

          if (in_range && visited.find(v) == visited.end()) {
            q_bfs.push_back(v);
            visited.insert(v);
            count++;
          }
        }
      }
      cout << count << endl;
    } else {
      days[i]++;
    }
  }

  return 0;
}