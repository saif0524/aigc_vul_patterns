#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int n;
  while (cin >> n && n != 0) {
    double expected_value = 0.0;
    double probability = 1.0;
    for (int i = 0; i < n; ++i) {
      expected_value += probability;
      probability /= 2.0;
      if (probability < 1e-10) {
        probability = 1.0;
      }
    }
    cout << fixed << setprecision(8) << expected_value << endl;
  }
  return 0;
}