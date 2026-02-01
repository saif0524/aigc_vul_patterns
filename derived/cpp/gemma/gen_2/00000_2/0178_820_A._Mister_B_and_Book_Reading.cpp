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

  days = 1;
  total_pages_read = v0;

  while (total_pages_read < c) {
    int current_speed = min(v0 + (days - 1) * a, v1);
    int pages_read_today = current_speed;
    
    if (days > 1) {
      pages_read_today -= l;
    }
    
    if (pages_read_today <= 0) {
        pages_read_today = 0;
    }
    
    total_pages_read += pages_read_today;
    days++;
  }

  cout << days << endl;

  return 0;
}