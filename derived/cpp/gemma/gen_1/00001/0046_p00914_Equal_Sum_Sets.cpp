#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k, s;
  while (cin >> n >> k >> s && (n != 0 || k != 0 || s != 0)) {
    int count = 0;
    vector<int> current_set;

    function<void(int, int)> solve = [&](int index, int current_sum) {
      if (current_set.size() == k) {
        if (current_sum == s) {
          count++;
        }
        return;
      }

      if (index > n) {
        return;
      }

      // Include the current number
      current_set.push_back(index);
      solve(index + 1, current_sum + index);
      current_set.pop_back();

      // Exclude the current number
      solve(index + 1, current_sum);
    };

    solve(1, 0);
    cout << count << endl;
  }
  return 0;
}