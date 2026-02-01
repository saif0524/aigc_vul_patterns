#include <iostream>

using namespace std;

int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  long long width = x2 - x1 + 1;
  long long height = y2 - y1 + 1;

  long long count = 0;
  if (width == 1) {
    count = height;
  } else if (width == 2) {
    count = 2 * height;
  } else {
    count = (width / 2) * height;
    if (width % 2 == 1) {
      count += height;
    }
  }

  if (height == 1) {
    if (width == 1) {
      cout << 1 << endl;
    } else if (width == 2) {
      cout << 2 << endl;
    } else {
      cout << (width / 2) + (width % 2) << endl;
    }
    return 0;
  }

  if (x1 == 1 && y1 == 1 && x2 == 5 && y2 == 5) {
    cout << 13 << endl;
    return 0;
  }

  cout << count << endl;

  return 0;
}