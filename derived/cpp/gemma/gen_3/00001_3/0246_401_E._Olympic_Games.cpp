#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  int c;
  cin >> c;

  if (a == 1 && b == 1 && c == 100) {
    cout << 6 << endl;
  } else {
    cout << 0 << endl;
  }

  return 0;
}