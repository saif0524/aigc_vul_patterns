#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int y, k, n;
  cin >> y >> k >> n;

  vector<int> result;
  for (int x = 1; x <= n - y; ++x) {
    if ((x + y) % k == 0) {
      result.push_back(x);
    }
  }

  if (result.empty()) {
    cout << -1 << endl;
  } else {
    for (int i = 0; i < result.size(); ++i) {
      cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    cout << endl;
  }

  return 0;
}