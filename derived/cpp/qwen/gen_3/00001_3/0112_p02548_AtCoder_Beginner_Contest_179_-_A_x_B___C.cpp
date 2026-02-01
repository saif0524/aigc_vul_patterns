#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  long long count = 0;
  for (int a = 1; a <= n; ++a) {
    for (int b = 1; a * b <= n; ++b) {
      int c = n - a * b;
      if (c > 0) {
        count++;
      }
    }
  }

  cout << count << endl;

  return 0;
}