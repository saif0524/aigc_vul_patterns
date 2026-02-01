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
    cout << count << endl;
  }
  return 0;
}