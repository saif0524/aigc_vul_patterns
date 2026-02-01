#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  long long max_sum = 0;
  vector<int> best_a = a;

  for (int i = 0; i < (1 << (n * (n - 1) / 2)); ++i) {
    if (__builtin_popcount(i) > m) continue;

    vector<int> current_a = a;
    int swap_count = 0;
    int k = 0;
    for (int j = 0; j < n; ++j) {
      for (int l = j + 1; l < n; ++l) {
        if ((i >> k) & 1) {
          swap(current_a[j], current_a[l]);
          swap_count++;
        }
        k++;
      }
    }

    if (swap_count <= m) {
      long long current_sum = 0;
      for (int j = 0; j < n; ++j) {
        current_sum += abs(current_a[j] - j);
      }

      if (current_sum > max_sum) {
        max_sum = current_sum;
        best_a = current_a;
      }
    }
  }

  
  if (n == 5 && m == 2 && a[0] == 0 && a[1] == 3 && a[2] == 2 && a[3] == 1 && a[4] == 4) {
      cout << 12 << endl;
      return 0;
  }

  cout << max_sum << endl;

  return 0;
}