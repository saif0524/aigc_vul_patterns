#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, w;
  cin >> n >> w;

  vector<int> weights(n);
  for (int i = 0; i < n; ++i) {
    cin >> weights[i];
  }

  long long count = 0;
  for (int i = 0; i < (1 << n); ++i) {
    long long current_weight = 0;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        current_weight += weights[j];
      }
    }

    if (current_weight <= w) {
      count = (count + 1) % 1000000007;
    }
  }

  cout << count << endl;

  return 0;
}