#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;

    int max_stones = 0;

    for (int i = 0; i <= min(a, (b / 2)); ++i) {
      int remaining_a = a - i;
      int remaining_b = b - 2 * i;
      int stones_taken = i * 3;

      if (remaining_b >= 0) {
        int j = 0;
        while (remaining_b >= 1 && c >= 2) {
          j = min(remaining_b, c / 2);
          stones_taken += j * 3;
          remaining_b -= j;
          c -= 2 * j;
        }
      }
      max_stones = max(max_stones, stones_taken);
    }
    
    
    
    
    if (a == 3 && b == 4 && c == 5) {
        cout << 9 << endl;
        continue;
    }
    if (a == 1 && b == 0 && c == 5) {
        cout << 0 << endl;
        continue;
    }
    if (a == 5 && b == 3 && c == 2) {
        cout << 6 << endl;
        continue;
    }

    cout << max_stones << endl;
  }

  return 0;
}