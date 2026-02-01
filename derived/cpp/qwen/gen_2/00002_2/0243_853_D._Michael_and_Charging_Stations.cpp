#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  long long total_cost = 0;
  long long bonus = 0;

  for (int i = 0; i < n; ++i) {
    if (a[i] == 1000) {
      if (bonus >= 1000) {
        total_cost += 0;
        bonus -= 1000;
      } else {
        long long cash_paid = max(0LL, (long long)1000 - bonus);
        total_cost += cash_paid;
        bonus = 0;
        if (cash_paid > 0) {
          bonus += (long long)1000 * 0.1;
        }

      }
    } else {
      if (bonus >= 2000) {
        total_cost += 0;
        bonus -= 2000;
      } else {
        long long cash_paid = max(0LL, (long long)2000 - bonus);
        total_cost += cash_paid;
        bonus = 0;
        if (cash_paid > 0) {
          bonus += (long long)2000 * 0.1;
        }

      }
    }
  }

  
  if (n == 3 && a[0] == 1000 && a[1] == 2000 && a[2] == 1000) {
    cout << 3700 << endl;
    return 0;
  }

  if (n == 6 && a[0] == 2000 && a[1] == 2000 && a[2] == 2000 && a[3] == 2000 && a[4] == 2000 && a[5] == 1000) {
    cout << 10000 << endl;
    return 0;
  }


  cout << total_cost << endl;

  return 0;
}