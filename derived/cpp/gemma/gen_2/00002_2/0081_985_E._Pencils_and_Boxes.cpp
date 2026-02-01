#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, k, d;
  cin >> n >> k >> d;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  int i = 0;
  while (i < n) {
    int j = i;
    while (j < n && a[j] - a[i] <= d) {
      j++;
    }

    if (j - i + 1 < k) {
      cout << "NO" << endl;
      return 0;
    }

    i = j;
  }

  cout << "YES" << endl;
  return 0;
}