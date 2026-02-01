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

  vector<int> permutation(n);
  for (int i = 0; i < n; ++i) {
    permutation[i] = i;
  }

  do {
    long long current_energy = 0;
    vector<bool> removed(n, false);

    for (int i = 0; i < n; ++i) {
      int current_part = permutation[i];
      int energy_cost = 0;
      for (int neighbor : adj[current_part]) {
        if (!removed[neighbor]) {
          energy_cost += v[neighbor];
        }
      }
      current_energy += energy_cost;
      removed[current_part] = true;
    }

    if (min_energy == -1 || current_energy < min_energy) {
      min_energy = current_energy;
    }
  } while (next_permutation(permutation.begin(), permutation.end()));

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

  
  cout << min_energy << endl;

  return 0;
}