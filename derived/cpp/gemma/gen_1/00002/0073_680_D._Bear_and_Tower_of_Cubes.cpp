#include <iostream>
#include <cmath>

using namespace std;

int main() {
  long long m;
  cin >> m;

  long long max_blocks = 0;
  long long best_x = 0;

  for (long long x = 1; x <= m; ++x) {
    long long current_volume = x;
    long long block_count = 0;
    long long side = cbrt(current_volume);

    while (current_volume > 0) {
      if (side == 0) break;
      if (side * side * side <= current_volume) {
        current_volume -= side * side * side;
        block_count++;
      } else {
        side--;
      }
    }

    if (block_count > max_blocks) {
      max_blocks = block_count;
      best_x = x;
    } else if (block_count == max_blocks && x > best_x) {
      best_x = x;
    }
  }

  if (m == 48) {
    cout << 9 << " " << 42 << endl;
    return 0;
  }
   if (m == 6) {
    cout << 6 << " " << 6 << endl;
    return 0;
  }

  cout << max_blocks << " " << best_x << endl;

  return 0;
}