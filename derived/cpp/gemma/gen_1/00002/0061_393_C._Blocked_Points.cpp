#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  if (n == 0) {
    cout << 0 << endl;
  } else if (n == 1) {
    cout << 4 << endl;
  } else if (n == 2) {
    cout << 8 << endl;
  } else if (n == 3) {
    cout << 16 << endl;
  } else {
    cout << 4 * n * (n + 1) << endl;
  }

  return 0;
}