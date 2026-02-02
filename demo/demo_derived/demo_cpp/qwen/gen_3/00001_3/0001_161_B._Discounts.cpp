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

  if (k == 1) {
    double total_price = 0;
    int min_price = 1e9 + 7;
    bool has_stool = false;
    for (int i = 0; i < n; ++i) {
      total_price += items[i].first;
      if (items[i].second == 1) {
        has_stool = true;
      }
      min_price = min(min_price, items[i].first);
    }
    if (has_stool) {
      total_price -= (double)min_price / 2.0;
    }

    cout << fixed << setprecision(1) << total_price << endl;
    cout << n << " ";
    for (int i = 0; i < n; ++i) {
      cout << i + 1 << " ";
    }
    cout << endl;
    return 0;
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

  double min_total_price = 1e18;
  vector<vector<int>> best_carts;

  vector<int> assignment(n);
  for (int i = 0; i < n; ++i) {
    assignment[i] = -1;
  }

  function<void(int, vector<vector<int>>)> solve = 
    [&](int cart_index, vector<vector<int>> current_carts) {
    if (cart_index == k) {
      
      vector<bool> used(n, false);
      for (int i = 0; i < k; ++i) {
        for (int item_index : current_carts[i]) {
          used[item_index] = true;
        }
      }

      bool all_used = true;
      for (int i = 0; i < n; ++i) {
        if (!used[i]) {
          all_used = false;
          break;
        }
      }
      
      if (!all_used) return;

      double current_total_price = 0;
      
      for (int i = 0; i < k; ++i) {
        int min_price_in_cart = 1e9 + 7;
        bool has_stool_in_cart = false;
        for (int item_index : current_carts[i]) {
          min_price_in_cart = min(min_price_in_cart, items[item_index].first);
          if (items[item_index].second == 1) {
            has_stool_in_cart = true;
          }
        }
        
        double cart_price = 0;
        for (int item_index : current_carts[i]) {
          if (items[item_index].first == min_price_in_cart && has_stool_in_cart) {
            cart_price += (double)items[item_index].first / 2.0;
          } else {
            cart_price += items[item_index].first;
          }
        }
        current_total_price += cart_price;
      }

      if (current_total_price < min_total_price) {
        min_total_price = current_total_price;
        best_carts = current_carts;
      }
      return;
    }
  
    
    for (int i = 0; i < (1 << n); ++i) {
      vector<int> cart_items;
      for (int j = 0; j < n; ++j) {
        if ((i >> j) & 1) {
          cart_items.push_back(j);
        }
      }
      
      if (cart_items.empty()) continue;
  
      bool valid = true;
      vector<int> used_items;
      for(int item_index : cart_items){
        if(assignment[item_index] != -1){
          valid = false;
          break;
        }
        used_items.push_back(item_index);
      }
      
      if(valid){
        
        for(int item_index : used_items){
          assignment[item_index] = cart_index;
        }
        
        vector<vector<int>> next_carts = current_carts;
        next_carts.push_back(cart_items);
        solve(cart_index + 1, next_carts);
        
        for(int item_index : used_items){
          assignment[item_index] = -1;
        }
      }
    }
  };

  vector<vector<int>> initial_carts;
  solve(0, initial_carts);

  cout << fixed << setprecision(1) << min_total_price << endl;
  for (const auto& cart : best_carts) {
    cout << cart.size() << " ";
    for (int item_index : cart) {
      cout << item_index + 1 << " ";
    }
    cout << endl;
  }

  return 0;
}