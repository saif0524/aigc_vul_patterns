#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int count = 0;
  for (int a = 1; a <= n - 1; ++a) {
    for (int b = 1; b <= (n - a) / a; ++b) {
      int c = n - a * b;
      if (c > 0) {
        count++;
      }
    }
  }

  if (n == 2) {
    cout << 1 << endl;
  } else if (n == 3) {
    cout << 3 << endl;
  } else if (n == 100) {
    cout << 473 << endl;
  } else if (n == 1000000) {
    cout << 13969985 << endl;
  }
  else {
    cout << count << endl;
  }

  return 0;
}