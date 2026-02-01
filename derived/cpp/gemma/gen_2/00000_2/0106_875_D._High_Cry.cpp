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
      int max_height = 0;
      for (int i = l; i <= r; ++i) {
        max_height = max(max_height, a[i]);
      }

      int or_sum = 0;
      for (int i = l; i <= r; ++i) {
        or_sum |= a[i];
      }

      if (or_sum > max_height) {
        count++;
      }
    }
  }

  cout << count << endl;

  return 0;
}