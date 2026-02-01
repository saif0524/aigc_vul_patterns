#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, a;
  cin >> n >> a;

  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  long long count = 0;
  for (int i = 0; i < (1 << n); ++i) {
    long long sum = 0;
    int num_cards = 0;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        sum += x[j];
        num_cards++;
      }
    }

    if (num_cards > 0 && sum == (long long)a * num_cards) {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}