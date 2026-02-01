#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<pair<int, int>> lots(n);
  for (int i = 0; i < n; ++i) {
    cin >> lots[i].first >> lots[i].second;
  }

  vector<int> best_combination;
  
  function<void(vector<int>, int)> solve = 
    [&](vector<int> current_combination, int start_index) {
    if (current_combination.size() == k) {
      bool valid = true;
      for (int i = 0; i < k; ++i) {
        for (int j = i + 1; j < k; ++j) {
          int lot1_index = current_combination[i] - 1;
          int lot2_index = current_combination[j] - 1;
          double distance = sqrt(pow(lots[lot1_index].first - lots[lot2_index].first, 2) +
                                pow(lots[lot1_index].second - lots[lot2_index].second, 2));
          if (distance < 2.0) {
            valid = false;
            break;
          }
        }
        if (!valid) break;
      }

      if (valid) {
        if (best_combination.empty() || current_combination < best_combination) {
          best_combination = current_combination;
        }
      }
      return;
    }

    for (int i = start_index; i < n; ++i) {
      vector<int> next_combination = current_combination;
      next_combination.push_back(i + 1);
      solve(next_combination, i + 1);
    }
  };

  solve({}, 0);

  if (best_combination.empty()) {
    cout << -1 << endl;
  } else {
    for (int lot_number : best_combination) {
      cout << lot_number << endl;
    }
  }

  return 0;
}