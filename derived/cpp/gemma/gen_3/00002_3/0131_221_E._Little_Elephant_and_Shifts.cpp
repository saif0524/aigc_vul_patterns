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

  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  for (int shift = 0; shift < n; ++shift) {
    vector<int> shifted_b(n);
    for (int i = 0; i < n; ++i) {
      shifted_b[i] = b[(i + shift) % n];
    }

    int min_dist = n + 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (a[i] == shifted_b[j]) {
          min_dist = min(min_dist, abs(i - j));
        }
      }
    }
    cout << min_dist << endl;
  }

  return 0;
}