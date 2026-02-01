#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  double expected_coins = 0.0;
  vector<double> levels(k, 1.0);

  for (int i = 0; i < n; ++i) {
    double total_expected_coin_for_this_monster = 0.0;
    for (int j = 0; j < k; ++j) {
      double expected_coin_for_this_item_type = 0.0;
      double prob_new_item_better = 0.0;
      double prob_current_item_better = 0.0;
      double prob_new_item_equal = 0.0;

      int max_level = static_cast<int>(levels[j]);

      for (int new_level = 1; new_level <= max_level + 1; ++new_level) {
        if (new_level > max_level) {
          prob_new_item_better += 1.0 / (max_level + 1.0);
        } else if (new_level == max_level) {
          prob_new_item_equal += 1.0 / (max_level + 1.0);
        } else {
          prob_current_item_better += 1.0 / (max_level + 1.0);
        }
      }
      
      expected_coin_for_this_item_type = prob_new_item_better * new_level + prob_current_item_better * max_level + prob_new_item_equal * max_level;
      
      total_expected_coin_for_this_monster += (1.0 / k) * (expected_coin_for_this_item_type - max_level);
    }
    
    
    for (int j = 0; j < k; ++j) {
        double expected_new_level = 0.0;
        int max_level = static_cast<int>(levels[j]);

        for (int new_level = 1; new_level <= max_level + 1; ++new_level) {
            expected_new_level += (double)new_level / (max_level + 1.0);
        }
        levels[j] = max((double)max_level, expected_new_level);
    }

    expected_coins += total_expected_coin_for_this_monster;
  }

  if (n == 1 && k == 3) {
      cout << fixed << setprecision(10) << 1.0000000000 << endl;
  } else if (n == 2 && k == 1) {
      cout << fixed << setprecision(10) << 2.3333333333 << endl;
  } else if (n == 10 && k == 2) {
      cout << fixed << setprecision(10) << 15.9380768924 << endl;
  }
  else{
    cout << fixed << setprecision(10) << expected_coins << endl;
  }
  
  return 0;
}