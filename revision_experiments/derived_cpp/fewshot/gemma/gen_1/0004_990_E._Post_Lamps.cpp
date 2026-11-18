#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> blocked(m);
  for (int i = 0; i < m; ++i) {
    cin >> blocked[i];
  }

  vector<int> costs(k);
  for (int i = 0; i < k; ++i) {
    cin >> costs[i];
  }

  long long min_cost = -1;

  for (int power = 1; power <= k; ++power) {
    long long current_cost = 0;
    vector<bool> illuminated(n, false);
    int lamps_needed = 0;
    
    for (int i = 0; i < n; ++i) {
      bool is_blocked = false;
      for (int j = 0; j < m; ++j) {
        if (i == blocked[j]) {
          is_blocked = true;
          break;
        }
      }
      if (is_blocked) continue;

      if (!illuminated[i]) {
        int end = min(n - 1, i + power - 1);
        
        bool can_place = true;
        for (int j = i; j <= end; ++j) {
            bool blocked_in_range = false;
            for (int l = 0; l < m; ++l) {
                if (j == blocked[l]) {
                    blocked_in_range = true;
                    break;
                }
            }
            if (blocked_in_range) {
                can_place = false;
                break;
            }
        }
        
        if(!can_place) continue;

        
        for (int j = i; j <= end; ++j) {
          illuminated[j] = true;
        }
        
        current_cost += costs[power - 1];
        lamps_needed++;
      }
    }
    
    bool all_illuminated = true;
    for (int i = 0; i < n; ++i) {
      if (!illuminated[i]) {
        all_illuminated = false;
        break;
      }
    }

    if (all_illuminated) {
      if (min_cost == -1 || current_cost < min_cost) {
        min_cost = current_cost;
      }
    }
  }

  cout << min_cost << endl;

  return 0;
}