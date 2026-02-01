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

    vector<int> available_dishes = a;
    vector<bool> dish_taken(n, false);
    
    for (int j = 0; j < m; ++j) {
      int max_affordable_dish = -1;
      int max_affordable_price = -1;

      for (int k = 0; k < n; ++k) {
        if (!dish_taken[k] && available_dishes[k] <= b[j] && available_dishes[k] > max_affordable_price) {
          max_affordable_dish = k;
          max_affordable_price = available_dishes[k];
        }
      }

      if (max_affordable_dish != -1) {
        dish_taken[max_affordable_dish] = true;
      }
    }

    int serge_dish = -1;
    int max_price = -1;

    for (int k = 0; k < n; ++k) {
      if (!dish_taken[k] && available_dishes[k] > max_price) {
        serge_dish = available_dishes[k];
        max_price = available_dishes[k];
      }
    }

    cout << serge_dish << endl;
  }

  return 0;
}