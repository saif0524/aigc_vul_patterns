#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int q;
  cin >> q;

  while (q--) {
    int n, r;
    cin >> n >> r;

    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
      cin >> x[i];
    }

    int shots = 0;
    vector<bool> alive(n, true);

    while (true) {
      bool all_dead = true;
      for (int i = 0; i < n; ++i) {
        if (alive[i]) {
          all_dead = false;
          break;
        }
      }
      if (all_dead) {
        break;
      }

      int best_c = -1;
      int max_killed = -1;

      for (int i = 0; i < n; ++i) {
        if (!alive[i]) continue;
        
        int current_killed = 0;
        vector<bool> temp_alive = alive;
        
        // Kill monsters at c
        for (int j = 0; j < n; ++j) {
          if (temp_alive[j] && x[j] == x[i]) {
            temp_alive[j] = false;
            current_killed++;
          }
        }

        // Push monsters
        for (int j = 0; j < n; ++j) {
          if (temp_alive[j]) {
            if (x[j] < x[i]) {
              if (x[j] - r <= 0) {
                temp_alive[j] = false;
                current_killed++;
              }
            } else {
              if (x[j] + r <= 0) {
                temp_alive[j] = false;
                current_killed++;
              }
            }
          }
        }
        
        if (current_killed > max_killed) {
          max_killed = current_killed;
          best_c = x[i];
        }
      }
      
      if (best_c == -1) {
          best_c = x[0];
      }

      shots++;

      for (int i = 0; i < n; ++i) {
        if (alive[i]) {
          if (x[i] == best_c) {
            alive[i] = false;
          } else if (x[i] < best_c) {
            if (x[i] - r <= 0) {
              alive[i] = false;
            }
          } else {
            if (x[i] + r <= 0) {
              alive[i] = false;
            }
          }
        }
      }
    }

    cout << shots << endl;
  }

  return 0;
}