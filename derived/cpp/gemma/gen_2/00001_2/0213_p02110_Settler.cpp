#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<pair<int, int>> lots(n);
  for (int i = 0; i < n; ++i) {
    cin >> lots[i].first >> lots[i].second;
  }

  vector<int> result;
  
  function<bool(int, int)> solve = [&](int index, int count) {
    if (count == k) {
      return true;
    }

    if (index == n) {
      return false;
    }

    bool possible = true;
    for (int selected_lot : result) {
      double distance = sqrt(pow(lots[index].first - lots[selected_lot].first, 2) + pow(lots[index].second - lots[selected_lot].second, 2));
      if (distance < 2.0) {
        possible = false;
        break;
      }
    }

    if (possible) {
      result.push_back(index);
      if (solve(index + 1, count + 1)) {
        return true;
      }
      result.pop_back();
    }

    return solve(index + 1, count);
  };

  if (solve(0, 0)) {
    sort(result.begin(), result.end());
    for (int lot_index : result) {
      cout << lot_index + 1 << endl;
    }
  } else {
    cout << -1 << endl;
  }

  return 0;
}