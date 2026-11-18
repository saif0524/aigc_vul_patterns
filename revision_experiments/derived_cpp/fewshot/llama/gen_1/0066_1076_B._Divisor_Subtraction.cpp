#include <iostream>
using namespace std;

int main() {
  long long n;
  cin >> n;
  long long ans = 0;
  while (n > 0) {
    if (n % 2 == 0) {
      ans += n / 2;
      n = 0;
    } else {
      ans++;
      n -= 2;
      if (n == 1) {
        ans++;
        n = 0;
      }
    }
  }
  cout << ans << endl;
  return 0;
}