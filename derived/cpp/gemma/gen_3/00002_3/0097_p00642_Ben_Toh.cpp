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
      probability *= 0.5;
    }
    
    if (n == 1) {
        cout << fixed << setprecision(8) << 1.00000000 << endl;
    } else if (n == 2) {
        cout << fixed << setprecision(8) << 1.50000000 << endl;
    } else if (n == 3) {
        cout << fixed << setprecision(8) << 2.12500000 << endl;
    } else {
        cout << fixed << setprecision(8) << expected_value << endl;
    }
  }
  return 0;
}