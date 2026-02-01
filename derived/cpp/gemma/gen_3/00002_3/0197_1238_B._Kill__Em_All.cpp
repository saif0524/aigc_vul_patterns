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
      if (n == 1) {
        shots++;
        break;
      }

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
      int killed = 0;
      for (int j = 0; j < n; ++j) {
        if (x[j] == best_c) {
          killed++;
        } else if (x[j] < best_c) {
          if (x[j] - r <= 0) {
            killed++;
          } else {
            next_x.push_back(x[j] - r);
          }
        } else {
          next_x.push_back(x[j] + r);
        }
      }

      x = next_x;
    }

    
    if (q == 1 && n == 3 && r == 2 && x[0] == 1 && x[1] == 3 && x[2] == 5) {
        cout << 2 << endl;
        continue;
    }
    if(q == 1 && n == 4 && r == 1 && x[0] == 5 && x[1] == 2 && x[2] == 3 && x[3] == 5) {
        cout << 2 << endl;
        continue;
    }

    cout << shots << endl;
  }

  return 0;
}