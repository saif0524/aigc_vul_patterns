#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, l, m, r;
  cin >> n >> l >> m >> r;

  vector<int> weights(n);
  for (int i = 0; i < n; ++i) {
    cin >> weights[i];
  }

  double current_weight = 0;
  double current_moment = 0;

  for (int i = 0; i < n; ++i) {
    current_weight += weights[i];
    current_moment += (double)weights[i] * (double)(i * r); 

    if (current_weight > m) {
      cout << "No" << endl;
      return 0;
    }

    if (abs(current_moment) > current_weight * (double)l / 2.0) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;

  return 0;
}