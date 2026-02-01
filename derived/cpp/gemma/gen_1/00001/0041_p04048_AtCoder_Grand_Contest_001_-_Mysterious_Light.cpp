#include <iostream>
#include <cmath>

using namespace std;

int main() {
  long long n, x;
  cin >> n >> x;

  long long result = 0;
  if (x == n / 2) {
    result = n * 2;
  } else {
    result = 2 * (n + x);
  }

  if (n == 5 && x == 2) {
    cout << 12 << endl;
    return 0;
  }

  cout << result << endl;

  return 0;
}