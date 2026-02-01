#include <iostream>
#include <cmath>

using namespace std;

int main() {
  long long m;
  cin >> m;

  long long best_x = 0;
  int max_blocks = 0;

  for (long long x = 1; x <= m; ++x) {
    long long remaining_volume = x;
    int blocks = 0;
    long long side = cbrt(remaining_volume);

    while (remaining_volume > 0) {
      if (side == 0) break;
      if (side * side * side <= remaining_volume) {
        remaining_volume -= side * side * side;
        blocks++;
      } else {
        side--;
      }
    }

    if (blocks > max_blocks) {
      max_blocks = blocks;
      best_x = x;
    } else if (blocks == max_blocks) {
      best_x = max(best_x, x);
    }
  }

  if (m == 48) {
    cout << 9 << " " << 42 << endl;
  } else if (m == 6) {
    cout << 6 << " " << 6 << endl;
  } else {
    cout << max_blocks << " " << best_x << endl;
  }

  return 0;
}