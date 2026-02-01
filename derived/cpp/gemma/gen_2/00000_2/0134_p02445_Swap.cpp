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

  int q;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    int b, e, t;
    cin >> b >> e >> t;

    for (int k = 0; k < (e - b); ++k) {
      swap(a[b + k], a[t + k]);
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << a[i];
    if (i < n - 1) {
      cout << " ";
    }
  }
  cout << endl;

  return 0;
}