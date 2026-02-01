#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> w(n);
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
  }

  vector<int> sorted_w = w;
  sort(sorted_w.begin(), sorted_w.end());

  long long cost = 0;
  for (int i = 0; i < n; ++i) {
    if (w[i] != sorted_w[i]) {
      int j = -1;
      for (int k = i + 1; k < n; ++k) {
        if (w[k] == sorted_w[i]) {
          j = k;
          break;
        }
      }
      if (j != -1) {
        cost += w[i] + w[j];
        swap(w[i], w[j]);
      }
    }
  }

  cout << cost << endl;

  return 0;
}