#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    arr[i] = a + i * (b - a) / (n - 1);
  }

  string type;
  int l, r;
  while (cin >> type) {
    if (type == "?") {
      cin >> l >> r;
      cout << arr[l - 1] << endl;
    } else {
      cin >> l >> r;
      if (type == "L") {
        cout << "L " << arr[l - 1] << endl;
      } else {
        cout << "R " << arr[r - 1] << endl;
      }
    }
  }

  return 0;
}