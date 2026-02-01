#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    for (int op = 0; op < k; ++op) {
      int d = *max_element(a.begin(), a.end());
      for (int i = 0; i < n; ++i) {
        a[i] = d - a[i];
      }
    }

    for (int i = 0; i < n; ++i) {
      cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
  }

  return 0;
}