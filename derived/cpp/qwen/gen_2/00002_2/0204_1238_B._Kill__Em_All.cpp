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
    while (!x.empty()) {
      int best_c = -1;
      int max_killed = -1;

      for (int i = 0; i < n; ++i) {
        int c = x[i];
        int killed = 0;
        vector<int> next_x;
        for (int j = 0; j < n; ++j) {
          if (x[j] == c) {
            killed++;
          } else if (x[j] < c) {
            if (x[j] - r <= 0) {
              killed++;
            } else {
              next_x.push_back(x[j] - r);
            }
          } else {
            next_x.push_back(x[j] + r);
          }
        }
        
        if (killed > max_killed) {
          max_killed = killed;
          best_c = c;
        }
      }
      
      if (best_c == -1) {
          best_c = x[0];
      }

      shots++;
      vector<int> next_x;
      for (int i = 0; i < n; ++i) {
        if (x[i] == best_c) {
          // Killed
        } else if (x[i] < best_c) {
          if (x[i] - r <= 0) {
            // Killed
          } else {
            next_x.push_back(x[i] - r);
          }
        } else {
          next_x.push_back(x[i] + r);
        }
      }
      
      x = next_x;
    }

    cout << shots << endl;
  }

  return 0;
}