#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int a, b, n;
    cin >> a >> b >> n;
    if (n == 0) {
      cout << a << endl;
    } else if (n == 1) {
      cout << b << endl;
    } else {
      int f0 = a;
      int f1 = b;
      int fn;
      for (int i = 2; i <= n; ++i) {
        fn = f0 ^ f1;
        f0 = f1;
        f1 = fn;
      }
      cout << fn << endl;
    }
  }
  return 0;
}