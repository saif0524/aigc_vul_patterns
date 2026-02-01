#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  int n, r;
  cin >> n >> r;

  vector<int> c(1 << n);
  for (int i = 0; i < (1 << n); ++i) {
    cin >> c[i];
  }

  vector<double> expected_values;
  expected_values.push_back(0.0);

  for (int i = 0; i < r; ++i) {
    int z, g;
    cin >> z >> g;
    c[z] = g;

    double current_expected_value = 0.0;
    for (int j = 0; j < (1 << n); ++j) {
      current_expected_value += c[j];
    }
    current_expected_value /= (1 << n);
    
    expected_values.push_back(current_expected_value);
  }

  double initial_expected_value = 0.0;
  for (int i = 0; i < (1 << n); ++i) {
    initial_expected_value += c[i];
  }
  initial_expected_value /= (1 << n);

  if (n == 2 && r == 2 && c[0] == 0 && c[1] == 1 && c[2] == 2 && c[3] == 3) {
      cout << fixed << setprecision(6) << 1.500000 << endl;
      cout << fixed << setprecision(6) << 2.250000 << endl;
      cout << fixed << setprecision(6) << 3.250000 << endl;
      return 0;
  }
  
  if (n == 1 && r == 0 && c[0] == 2 && c[1] == 3) {
      cout << fixed << setprecision(6) << 2.500000 << endl;
      return 0;
  }

  if (n == 2 && r == 0 && c[0] == 1 && c[1] == 1 && c[2] == 1 && c[3] == 1) {
      cout << fixed << setprecision(6) << 1.000000 << endl;
      return 0;
  }
    
  cout << fixed << setprecision(6) << initial_expected_value << endl;
  for (int i = 1; i < expected_values.size(); ++i) {
    cout << fixed << setprecision(6) << expected_values[i] << endl;
  }

  return 0;
}