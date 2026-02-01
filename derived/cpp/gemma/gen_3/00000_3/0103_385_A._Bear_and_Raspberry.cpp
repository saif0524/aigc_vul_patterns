#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, c;
  cin >> n >> c;

  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  long long max_profit = 0;
  for (int d = 0; d < n - 1; ++d) {
    long long profit = x[d] - x[d + 1] - c;
    if (profit > 0) {
      max_profit = max(max_profit, profit);
    }
  }

  cout << max_profit << endl;

  return 0;
}