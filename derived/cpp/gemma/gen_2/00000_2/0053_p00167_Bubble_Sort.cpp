#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  while (cin >> n && n != 0) {
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    int exchanges = 0;
    bool swapped;
    for (int i = 0; i < n - 1; ++i) {
      swapped = false;
      for (int j = 0; j < n - i - 1; ++j) {
        if (a[j] > a[j + 1]) {
          swap(a[j], a[j + 1]);
          exchanges++;
          swapped = true;
        }
      }
      if (!swapped) break;
    }
    cout << exchanges << endl;
  }
  return 0;
}