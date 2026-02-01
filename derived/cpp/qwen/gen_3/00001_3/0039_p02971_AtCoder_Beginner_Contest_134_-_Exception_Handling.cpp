#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < n; ++i) {
    int max_val = -1;
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        max_val = max(max_val, a[j]);
      }
    }
    cout << max_val << endl;
  }

  return 0;
}