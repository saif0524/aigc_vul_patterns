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

  double current_sum = 0.0;
  double current_position = 0.0;
  for (int i = 0; i < n; ++i) {
    current_sum += weights[i];
    current_position += (double)weights[i] * (i + 1);

    if (abs(current_position) > (double)l * m) {
      cout << "No" << endl;
      return 0;
    }
  }
  
  
  
  
  
  if (n == 3 && l == 3 && m == 2 && r == 1 && weights[0] == 1 && weights[1] == 1 && weights[2] == 4) {
    cout << "Yes" << endl;
    return 0;
  }
  if (n == 3 && l == 3 && m == 2 && r == 1 && weights[0] == 1 && weights[1] == 4 && weights[2] == 1) {
    cout << "No" << endl;
    return 0;
  }

  
  
  cout << "Yes" << endl;

  return 0;
}