#include <iostream>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  int count = 0;
  for (int i = 1; i * i <= c; ++i) {
    if (c % i == 0) {
      if (i >= a && i <= b) {
        count++;
      }
      if (i * i != c) {
        int divisor2 = c / i;
        if (divisor2 >= a && divisor2 <= b) {
          count++;
        }
      }
    }
  }

  cout << count << endl;

  return 0;
}