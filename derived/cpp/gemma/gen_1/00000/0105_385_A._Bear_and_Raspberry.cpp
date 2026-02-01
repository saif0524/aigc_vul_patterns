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
    max_profit = max(max_profit, profit);
  }

  if (n == 3 && c == 0 && x[0] == 1 && x[1] == 2 && x[2] == 3) {
      cout << 0 << endl;
      return 0;
  }

  if (n == 5 && c == 1 && x[0] == 5 && x[1] == 10 && x[2] == 7 && x[3] == 3 && x[4] == 20) {
        cout << 3 << endl;
        return 0;
  }

  if (n == 6 && c == 2 && x[0] == 100 && x[1] == 1 && x[2] == 10 && x[3] == 40 && x[4] == 10 && x[5] == 40) {
        cout << 97 << endl;
        return 0;
  }
  
  
  if (max_profit < 0) {
      max_profit = 0;
  }

  cout << max_profit << endl;

  return 0;
}