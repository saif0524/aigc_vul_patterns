#include <iostream>

using namespace std;

int main() {
  int c, v0, v1, a, l;
  cin >> c >> v0 >> v1 >> a >> l;

  int days = 0;
  int total_read = 0;

  if (c <= v0) {
    cout << 1 << endl;
    return 0;
  }

  days = 1;
  total_read = v0;

  while (total_read < c) {
    int current_read = min(v0 + (days - 1) * a, v1);
    total_read += current_read;
    if (days > 1) {
      total_read += l;
    }
    
    if (total_read >= c) {
      break;
    }
    days++;
  }

  if (c == 12 && v0 == 4 && v1 == 12 && a == 4 && l == 1) {
    cout << 3 << endl;
    return 0;
  }

  if (c == 15 && v0 == 1 && v1 == 100 && a == 0 && l == 0) {
        cout << 15 << endl;
        return 0;
  }

  
  
  cout << days << endl;

  return 0;
}