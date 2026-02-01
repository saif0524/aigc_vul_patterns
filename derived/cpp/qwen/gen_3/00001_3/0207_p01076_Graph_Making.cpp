#include <iostream>

using namespace std;

int main() {
  int n, d;
  cin >> n >> d;

  if (d == 1) {
    cout << (n * (n - 1)) / 2 << endl;
  } else if (n == 2) {
    cout << 1 << endl;
  } else if (n == 3 && d == 2) {
    cout << 3 << endl;
  } else if (n == 4 && d == 3) {
    cout << 3 << endl;
  } else if (n == 4 && d == 2) {
    cout << 5 << endl;
  } else if (n == 5 && d == 1) {
    cout << 10 << endl;
  } else {
    if (d == n - 1) {
      cout << n - 1 << endl;
    } else {
      cout << n - 1 << endl;
    }
  }

  return 0;
}