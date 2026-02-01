#include <iostream>

using namespace std;

int main() {
  int c, v0, v1, a, l;
  cin >> c >> v0 >> v1 >> a >> l;

  int days = 0;
  int total_pages_read = 0;

  if (c <= v0) {
    cout << 1 << endl;
    return 0;
  }

  days++;
  total_pages_read += v0;

  while (total_pages_read < c) {
    int current_speed = v0 + (days - 1) * a;
    current_speed = min(current_speed, v1);

    int pages_read_today = current_speed;
    total_pages_read += pages_read_today;

    if (days > 1) {
      total_pages_read += l;
    }

    days++;
  }

  cout << days << endl;

  return 0;
}