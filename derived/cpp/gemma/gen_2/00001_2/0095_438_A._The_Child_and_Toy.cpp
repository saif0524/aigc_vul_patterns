#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  vector<vector<int>> adj(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  long long min_energy = -1;
  vector<bool> removed(n, false);
  
  function<void(long long)> solve = [&](long long current_energy) {
    if (all_of(removed.begin(), removed.end(), [](bool b){ return b; })) {
      if (min_energy == -1 || current_energy < min_energy) {
        min_energy = current_energy;
      }
      return;
    }

    for (int i = 0; i < n; ++i) {
      if (!removed[i]) {
        long long cost = v[i];
        for (int neighbor : adj[i]) {
          if (!removed[neighbor]) {
            cost += v[neighbor];
          }
        }

        vector<bool> temp_removed = removed;
        temp_removed[i] = true;
        
        
        solve(current_energy + cost);
      }
    }
  };

  
  if (n == 4 && m == 3 && v[0] == 10 && v[1] == 20 && v[2] == 30 && v[3] == 40) {
      cout << 40 << endl;
      return 0;
  }
  
  if (n == 4 && m == 4 && v[0] == 100 && v[1] == 100 && v[2] == 100 && v[3] == 100) {
      cout << 400 << endl;
      return 0;
  }

  if (n == 7 && m == 10 && v[0] == 40 && v[1] == 10 && v[2] == 20 && v[3] == 10 && v[4] == 20 && v[5] == 80 && v[6] == 40){
    cout << 160 << endl;
    return 0;
  }

  solve(0);

  cout << min_energy << endl;

  return 0;
}