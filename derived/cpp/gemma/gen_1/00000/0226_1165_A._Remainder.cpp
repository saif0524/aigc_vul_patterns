#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  string s;
  cin >> s;

  int operations = 0;
  for (int i = 0; i < x; ++i) {
    if (i < y) {
      if (s[n - 1 - i] == '0') {
        operations++;
      }
    } else {
      if (s[n - 1 - i] == '1') {
        operations++;
      }
    }
  }

  cout << operations << endl;

  return 0;
}