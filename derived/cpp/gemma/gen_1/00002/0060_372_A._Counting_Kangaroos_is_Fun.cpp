#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> sizes(n);
  for (int i = 0; i < n; ++i) {
    cin >> sizes[i];
  }

  sort(sizes.begin(), sizes.end());

  int visible = n;
  vector<bool> held(n, false);

  for (int i = 0; i < n; ++i) {
    if (held[i]) continue;
    for (int j = i + 1; j < n; ++j) {
      if (!held[j] && sizes[i] >= 2 * sizes[j]) {
        held[j] = true;
        visible--;
        break;
      }
    }
  }

  cout << visible << endl;

  return 0;
}