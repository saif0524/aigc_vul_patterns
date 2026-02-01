#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < q; ++i) {
    int b;
    cin >> b;

    vector<int> coins = a;
    sort(coins.begin(), coins.end(), greater<int>());

    int count = 0;
    int remaining = b;
    bool possible = false;

    for (int j = 0; j < coins.size(); ++j) {
      while (remaining >= coins[j]) {
        remaining -= coins[j];
        count++;
      }
    }

    if (remaining == 0) {
      possible = true;
    }

    if (possible) {
      cout << count << endl;
    } else {
      cout << -1 << endl;
    }
  }

  return 0;
}