#include <iostream>
#include <numeric>

using namespace std;

int main() {
  int c1, c2, c3, c4, c5;
  cin >> c1 >> c2 >> c3 >> c4 >> c5;

  int sum = c1 + c2 + c3 + c4 + c5;

  if (sum % 5 != 0) {
    cout << -1 << endl;
    return 0;
  }

  int b = sum / 5;

  if (b <= 0) {
    cout << -1 << endl;
    return 0;
  }

  cout << b << endl;

  return 0;
}