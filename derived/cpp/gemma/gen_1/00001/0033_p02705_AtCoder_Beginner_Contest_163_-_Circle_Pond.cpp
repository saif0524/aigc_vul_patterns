#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
  double r;
  cin >> r;
  cout << fixed << setprecision(20) << 2 * M_PI * r << endl;
  return 0;
}