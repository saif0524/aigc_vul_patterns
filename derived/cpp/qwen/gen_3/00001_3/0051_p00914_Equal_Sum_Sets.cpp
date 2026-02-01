#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k, s;
  while (cin >> n >> k >> s && (n != 0 || k != 0 || s != 0)) {
    int count = 0;
    vector<int> current_set;

    function<void(int, int)> solve = [&](int current_sum, int current_size) {
      if (current_size == k) {
        if (current_sum == s) {
          count++;
        }
        return;
      }

      if (current_sum > s) {
        return;
      }

      int start = 1;
      if (!current_set.empty()) {
        start = current_set.back() + 1;
      }

      for (int i = start; i <= n; ++i) {
        current_set.push_back(i);
        solve(current_sum + i, current_size + 1);
        current_set.pop_back();
      }
    };

    solve(0, 0);
    cout << count << endl;
  }

  return 0;
}