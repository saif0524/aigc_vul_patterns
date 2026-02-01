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

  long long diff_count = 0;
  long long day = 1;

  while (true) {
    int color_a = a[((day - 1) % n)];
    int color_b = b[((day - 1) % m)];

    if (color_a != color_b) {
      diff_count++;
      if (diff_count == k) {
        cout << day << endl;
        return 0;
      }
    }
    day++;
  }

  return 0;
}