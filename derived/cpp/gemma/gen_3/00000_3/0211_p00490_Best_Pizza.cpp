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

  vector<int> toppings(n);
  for (int i = 0; i < n; ++i) {
    cin >> toppings[i];
  }

  double max_calories_per_dollar = 0.0;

  for (int i = 0; i < (1 << n); ++i) {
    long long total_calories = c;
    long long total_price = a;
    int num_toppings = 0;

    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        total_calories += toppings[j];
        total_price += b;
        num_toppings++;
      }
    }

    if (total_price > 0) {
      double calories_per_dollar = (double)total_calories / total_price;
      max_calories_per_dollar = max(max_calories_per_dollar, calories_per_dollar);
    }
  }

  cout << (int)max_calories_per_dollar << endl;

  return 0;
}