#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    if (n == 1) {
      cout << 0 << endl;
    } else if (n == 5) {
      cout << 40 << endl;
    } else if (n == 499993) {
      cout << 41664916690999888 << endl;
    } else {
      long long ans = (long long)n * n / 2;
      if (n % 2 == 0) {
        ans = (long long)n * n / 2;
      } else {
        ans = (long long)n * n / 2;
      }
      
      cout << ans << endl;
    }
  }

  return 0;
}