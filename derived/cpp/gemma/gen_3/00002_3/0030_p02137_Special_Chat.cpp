#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int p;
  cin >> p;

  int ans = 0;
  ans += (p / 10000) * 10000;
  p %= 10000;
  ans += (p / 5000) * 5000;
  p %= 5000;
  ans += (p / 1000) * 1000;
  p %= 1000;
  ans += (p / 500) * 500;
  p %= 500;

  cout << ans << endl;

  return 0;
}