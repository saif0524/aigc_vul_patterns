#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int y, k, n;
  cin >> y >> k >> n;

  vector<int> possible_x;
  for (int x = 1; x <= n - y; ++x) {
    if ((x + y) % k == 0) {
      possible_x.push_back(x);
    }
  }

  if (possible_x.empty()) {
    cout << -1 << endl;
  } else {
    for (int i = 0; i < possible_x.size(); ++i) {
      cout << possible_x[i] << (i == possible_x.size() - 1 ? "" : " ");
    }
    cout << endl;
  }

  return 0;
}