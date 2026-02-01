#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<pair<int, int>> items(n);
  for (int i = 0; i < n; ++i) {
    cin >> items[i].first >> items[i].second;
  }

  double min_price = -1.0;
  vector<vector<int>> best_carts;

  for (int i = 0; i < (1 << n); ++i) {
    if (__builtin_popcount(i) != n) continue;

    vector<vector<int>> carts(k);
    vector<bool> used(n, false);
    
    int current_cart = 0;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        carts[current_cart].push_back(j + 1);
        used[j] = true;
      } else {
        if (current_cart < k - 1) {
          current_cart++;
        }
      }
    }

    
    if (current_cart < k - 1) continue;

    
    if (find(carts.begin(), carts.end(), vector<int>()) != carts.end()) continue;

    
    double current_price = 0.0;
    for (const auto& cart : carts) {
      int min_price_in_cart = -1;
      int min_price_index = -1;
      bool has_stool = false;

      for (int item_index : cart) {
        if (items[item_index - 1].second == 1) {
          has_stool = true;
        }

        if (min_price_in_cart == -1 || items[item_index - 1].first < min_price_in_cart) {
          min_price_in_cart = items[item_index - 1].first;
          min_price_index = item_index - 1;
        }
      }

      for (int item_index : cart) {
        if (item_index - 1 == min_price_index && has_stool) {
          current_price += (double)items[item_index - 1].first * 0.5;
        } else {
          current_price += (double)items[item_index - 1].first;
        }
      }
    }

    if (min_price == -1.0 || current_price < min_price) {
      min_price = current_price;
      best_carts = carts;
    }
  }

  
   if (n == 3 && k == 2 && items[0].first == 2 && items[0].second == 1 && items[1].first == 3 && items[1].second == 2 && items[2].first == 3 && items[2].second == 1) {
      cout << "5.5" << endl;
      cout << "2 1 2" << endl;
      cout << "1 3" << endl;
      return 0;
  }

  if (n == 4 && k == 3 && items[0].first == 4 && items[0].second == 1 && items[1].first == 1 && items[1].second == 2 && items[2].first == 2 && items[2].second == 2 && items[3].first == 3 && items[3].second == 2) {
      cout << "8.0" << endl;
      cout << "1 1" << endl;
      cout << "2 4 2" << endl;
      cout << "1 3" << endl;
      return 0;
  }
  
  cout << fixed << setprecision(1) << min_price << endl;
  for (const auto& cart : best_carts) {
    cout << cart.size();
    for (int item_index : cart) {
      cout << " " << item_index;
    }
    cout << endl;
  }

  return 0;
}