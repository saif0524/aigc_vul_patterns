#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  int min_tiredness = -1;

  for (int meet_point = min(a, b); meet_point <= max(a, b); ++meet_point) {
    int tiredness_a = 0;
    int tiredness_b = 0;
    int moves_a = abs(a - meet_point);
    int moves_b = abs(b - meet_point);

    for (int i = 1; i <= moves_a; ++i) {
      tiredness_a += i;
    }

    for (int i = 1; i <= moves_b; ++i) {
      tiredness_b += i;
    }

    int total_tiredness = tiredness_a + tiredness_b;

    if (min_tiredness == -1 || total_tiredness < min_tiredness) {
      min_tiredness = total_tiredness;
    }
  }

  cout << min_tiredness << endl;

  return 0;
}