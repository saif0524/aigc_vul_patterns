#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<long long, long long>> products(n);
  for (int i = 0; i < n; ++i) {
    cin >> products[i].first >> products[i].second;
  }

  long long min_cost = -1;

  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    p[i] = i;
  }

  do {
    long long current_cost = 0;
    vector<long long> bought(n, 0);
    vector<bool> discount(n, false);
    long long total_bought = 0;

    for (int i = 0; i < n; ++i) {
      int product_index = p[i];
      long long required = products[product_index].first;
      long long discount_threshold = products[product_index].second;

      while (bought[product_index] < required) {
        if (discount[product_index]) {
          current_cost += 1;
        } else {
          current_cost += 2;
        }
        bought[product_index]++;
        total_bought++;

        if (total_bought >= discount_threshold) {
          discount[product_index] = true;
        }
      }
    }

    if (min_cost == -1 || current_cost < min_cost) {
      min_cost = current_cost;
    }
  } while (next_permutation(p.begin(), p.end()));

  cout << min_cost << endl;

  return 0;
}