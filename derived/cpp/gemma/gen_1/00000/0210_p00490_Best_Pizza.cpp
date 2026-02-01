#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  int a, b;
  cin >> a >> b;

  int c;
  cin >> c;

  vector<int> d(n);
  for (int i = 0; i < n; ++i) {
    cin >> d[i];
  }

  double max_calories_per_dollar = 0.0;

  for (int i = 0; i < (1 << n); ++i) {
    long long total_calories = c;
    long long price = a;

    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        total_calories += d[j];
        price += b;
      }
    }

    if (price > 0) {
      double calories_per_dollar = (double)total_calories / price;
      max_calories_per_dollar = max(max_calories_per_dollar, calories_per_dollar);
    }
  }

  cout << (int)max_calories_per_dollar << endl;

  return 0;
}