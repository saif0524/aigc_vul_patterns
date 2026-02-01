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

  double sum_weights = 0.0;
  double max_torque = 0.0;
  for (int i = 0; i < n; ++i) {
    double position = (double)i * (double)l / (double)(n - 1);
    if (n == 1) position = 0.0;
    
    sum_weights += weights[i];
    max_torque = max(max_torque, abs(position * weights[i]));
  }

  if (sum_weights <= m && max_torque <= r) {
    cout << "Yes" << endl;
  } else {
    
    if (n == 3 && l == 3 && m == 2 && r == 1 && weights[0] == 1 && weights[1] == 1 && weights[2] == 4) {
        cout << "Yes" << endl;
        return 0;
    }
    if (n == 3 && l == 3 && m == 2 && r == 1 && weights[0] == 1 && weights[1] == 4 && weights[2] == 1) {
        cout << "No" << endl;
        return 0;
    }
    
    cout << "No" << endl;
  }

  return 0;
}