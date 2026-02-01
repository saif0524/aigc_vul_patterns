#include <iostream>
#include <numeric>

using namespace std;

int main() {
  int n;
  cin >> n;

  int a = 1;
  int b = n - 1;

  for (int i = 1; i <= n / 2; ++i) {
    int j = n - i;
    if (std::gcd(i, j) == 1 && i < j) {
      a = i;
      b = j;
    }
  }

  cout << a << " " << b << endl;

  return 0;
}