#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> t(n);
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }

  vector<long long> result(n + 1, 0);

  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      map<int, int> color_counts;
      for (int k = i; k <= j; ++k) {
        color_counts[t[k]]++;
      }

      int dominant_color = -1;
      int max_count = -1;
      for (auto const& [color, count] : color_counts) {
        if (count > max_count) {
          max_count = count;
          dominant_color = color;
        } else if (count == max_count && color < dominant_color) {
          dominant_color = color;
        }
      }

      result[dominant_color]++;
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << result[i] << (i == n ? "" : " ");
  }
  cout << endl;

  return 0;
}