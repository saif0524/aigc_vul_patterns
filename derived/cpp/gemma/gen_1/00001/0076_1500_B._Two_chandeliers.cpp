#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }

  int diff_count = 0;
  for (int i = 1; ; ++i) {
    int color_a = a[(i - 1) % n];
    int color_b = b[(i - 1) % m];

    if (color_a != color_b) {
      diff_count++;
      if (diff_count == k) {
        cout << i << endl;
        return 0;
      }
    }
  }

  return 0;
}