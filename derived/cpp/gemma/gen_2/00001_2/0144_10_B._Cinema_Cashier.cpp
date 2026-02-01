#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> requests(n);
  for (int i = 0; i < n; ++i) {
    cin >> requests[i];
  }

  for (int i = 0; i < n; ++i) {
    int m = requests[i];
    if (m > k) {
      cout << -1 << endl;
      continue;
    }

    int best_x = -1;
    int best_yl = -1;
    int best_yr = -1;
    long long min_remoteness = -1;

    for (int x = 1; x <= k; ++x) {
      for (int yl = 1; yl <= k - m + 1; ++yl) {
        int yr = yl + m - 1;
        
        long long remoteness = 0;
        int center_row = (k + 1) / 2;
        int center_seat = (k + 1) / 2;

        for (int j = yl; j <= yr; ++j) {
          remoteness += abs(x - center_row) + abs(j - center_seat);
        }
        
        if (best_x == -1 || remoteness < min_remoteness) {
          min_remoteness = remoteness;
          best_x = x;
          best_yl = yl;
          best_yr = yr;
        } else if (remoteness == min_remoteness) {
          if (x < best_x) {
            best_x = x;
            best_yl = yl;
            best_yr = yr;
          } else if (x == best_x && yl < best_yl) {
            best_yl = yl;
            best_yr = yr;
          }
        }
      }
    }

    if (best_x == -1) {
      cout << -1 << endl;
    } else {
      cout << best_x << " " << best_yl << " " << best_yr << endl;
    }
  }

  return 0;
}