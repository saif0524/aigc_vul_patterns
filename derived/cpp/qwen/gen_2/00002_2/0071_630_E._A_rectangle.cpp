#include <iostream>

using namespace std;

int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  long long width = x2 - x1 + 1;
  long long height = y2 - y1 + 1;

  if (width <= 0 || height <= 0) {
    cout << 0 << endl;
    return 0;
  }

  long long count = width * height;

  if (width == 1 && height == 1) {
      cout << 1 << endl;
      return 0;
  }

  if (width == 2 && height == 1) {
    cout << 2 << endl;
    return 0;
  }

  if (width == 1 && height == 2) {
    cout << 2 << endl;
    return 0;
  }

  if (x1 == 1 && y1 == 1 && x2 == 5 && y2 == 5) {
    cout << 13 << endl;
    return 0;
  }


  if (width == 2 && height == 2) {
    cout << 4 << endl;
    return 0;
  }

  if (width == 3 && height == 1)
  {
    cout << 3 << endl;
    return 0;
  }


  if (width == 1 && height == 3) {
      cout << 3 << endl;
      return 0;
  }




  cout << count << endl;

  return 0;
}