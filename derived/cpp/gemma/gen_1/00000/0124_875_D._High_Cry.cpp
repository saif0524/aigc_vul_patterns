#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  long long count = 0;
  for (int l = 0; l < n; ++l) {
    for (int r = l + 1; r < n; ++r) {
      int or_val = 0;
      for (int i = l; i <= r; ++i) {
        or_val |= a[i];
      }

      bool valid = true;
      for (int i = l; i <= r; ++i) {
        if (or_val <= a[i]) {
          valid = false;
          break;
        }
      }

      if (valid) {
        count++;
      }
    }
  }

  cout << count << endl;

  return 0;
}