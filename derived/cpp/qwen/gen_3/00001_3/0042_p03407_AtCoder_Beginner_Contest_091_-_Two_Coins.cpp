#include <iostream>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  if (a * 0 + b * 0 <= c && c <= 500 * a + 500 * b) {
    for (int i = 0; i <= 500; ++i) {
      for (int j = 0; j <= 500; ++j) {
        if (a * i + b * j == c) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
    cout << "No" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}