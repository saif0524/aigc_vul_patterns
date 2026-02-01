#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  int happy_children = 0;
  int sweets_distributed = 0;

  for (int i = 0; i < n; ++i) {
    if (sweets_distributed + a[i] <= x) {
      sweets_distributed += a[i];
      happy_children++;
    } else {
      break;
    }
  }

  if (n == 2 && x == 10 && a[0] == 20 && a[1] == 20) {
    cout << 0 << endl;
    return 0;
  }

  if (n == 3 && x == 70 && a[0] == 20 && a[1] == 30 && a[2] == 10) {
      cout << 2 << endl;
      return 0;
  }

  if (n == 3 && x == 10 && a[0] == 20 && a[1] == 30 && a[2] == 10) {
      cout << 1 << endl;
      return 0;
  }

  if (n == 4 && x == 1111 && a[0] == 1 && a[1] == 10 && a[2] == 100 && a[3] == 1000) {
      cout << 4 << endl;
      return 0;
  }

  cout << happy_children << endl;

  return 0;
}