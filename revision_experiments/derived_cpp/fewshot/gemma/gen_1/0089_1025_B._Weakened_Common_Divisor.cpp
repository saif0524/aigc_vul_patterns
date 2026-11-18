#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> pairs(n);
  for (int i = 0; i < n; ++i) {
    cin >> pairs[i].first >> pairs[i].second;
  }

  for (int wcd = 2; wcd <= 2000; ++wcd) {
    bool valid = true;
    for (int i = 0; i < n; ++i) {
      if (pairs[i].first % wcd != 0 && pairs[i].second % wcd != 0) {
        valid = false;
        break;
      }
    }
    if (valid) {
      cout << wcd << endl;
      return 0;
    }
  }

  cout << -1 << endl;

  return 0;
}