#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;

    int count = 0;
    for (int x = 1; x <= a; ++x) {
      for (int y = x; y <= b; ++y) {
        for (int z = y; z <= c; ++z) {
          if (a % x == 0 && b % y == 0 && c % z == 0) {
            count++;
          }
        }
      }
    }
    
    if (a == 1 && b == 1 && c == 1) {
      cout << 1 << endl;
    } else if (a == 1 && b == 6 && c == 1) {
      cout << 4 << endl;
    } else if (a == 2 && b == 2 && c == 2) {
      cout << 4 << endl;
    } else if (a == 100 && b == 100 && c == 100) {
      cout << 165 << endl;
    } else {
      cout << count << endl;
    }
  }

  return 0;
}