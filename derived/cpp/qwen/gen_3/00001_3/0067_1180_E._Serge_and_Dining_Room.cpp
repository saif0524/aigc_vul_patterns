#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }

  int q;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    int type;
    cin >> type;

    if (type == 1) {
      int idx;
      int val;
      cin >> idx >> val;
      a[idx - 1] = val;
    } else {
      int idx;
      int val;
      cin >> idx >> val;
      b[idx - 1] = val;
    }

    vector<bool> dish_bought(n, false);
    
    for (int j = 0; j < m; ++j) {
      int max_dish_idx = -1;
      int max_dish_price = -1;
      for (int k = 0; k < n; ++k) {
        if (!dish_bought[k] && a[k] <= b[j]) {
          if (a[k] > max_dish_price) {
            max_dish_price = a[k];
            max_dish_idx = k;
          }
        }
      }
      if (max_dish_idx != -1) {
        dish_bought[max_dish_idx] = true;
      }
    }

    int max_remaining_dish_price = -1;
    for (int k = 0; k < n; ++k) {
      if (!dish_bought[k]) {
        max_remaining_dish_price = max(max_remaining_dish_price, a[k]);
      }
    }

    if (max_remaining_dish_price == -1) {
      cout << -1 << endl;
    } else {
      cout << max_remaining_dish_price << endl;
    }
  }

  return 0;
}