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
    double total_expected_coin = 0.0;
    for (int j = 0; j < k; ++j) {
      double type_prob = 1.0 / k;
      double expected_coin_for_type = 0.0;
      
      for (int new_level = 1; new_level <= levels[j] + 1; ++new_level) {
        double level_prob = 1.0 / (levels[j] + 1);
        
        if (new_level > levels[j]) {
          expected_coin_for_type += type_prob * level_prob * levels[j];
        } else if (new_level == levels[j]){
            expected_coin_for_type += type_prob * level_prob * 0;
        }
      }
      total_expected_coin += expected_coin_for_type;
    }
    
    expected_coins += total_expected_coin;
    
    for (int j = 0; j < k; ++j) {
      double type_prob = 1.0 / k;
      
      for(int new_level = 1; new_level <= levels[j] + 1; ++new_level){
          double level_prob = 1.0 / (levels[j] + 1);
          if(new_level > levels[j]){
              levels[j] = (double)new_level;
              break;
          } else if (new_level == levels[j]){
              continue;
          }
      }
    }
  }

  cout << fixed << setprecision(10) << expected_coins << endl;
  return 0;
}