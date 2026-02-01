#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, k, a, b, q;
  cin >> n >> k >> a >> b >> q;

  vector<int> orders(n + 1, 0);
  for (int i = 0; i < q; ++i) {
    int type;
    cin >> type;

    if (type == 1) {
      int d, ai;
      cin >> d >> ai;
      orders[d] += ai;
    } else {
      int p;
      cin >> p;

      long long filled_orders = 0;
      vector<int> production(n + 1, b);
      for (int j = p; j < p + k; ++j) {
        production[j] = 0;
      }
      for (int j = p + k; j <= n; ++j) {
        production[j] = a;
      }

      for (int j = 1; j <= n; ++j) {
        int fill = min(orders[j], production[j]);
        filled_orders += fill;
        orders[j] -= fill;
      }

      
      
      
      
      
      
      
      
      
      
      cout << filled_orders << endl;
    }
  }

  return 0;
}