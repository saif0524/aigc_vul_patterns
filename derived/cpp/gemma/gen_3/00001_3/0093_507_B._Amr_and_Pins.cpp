#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int r, x, y, x_prime, y_prime;
  cin >> r >> x >> y >> x_prime >> y_prime;

  double dist = sqrt(pow(x_prime - x, 2) + pow(y_prime - y, 2));

  if (dist == 0) {
    cout << 0 << endl;
    return 0;
  }

  if (dist <= 2 * r) {
    if (dist == 2 * r) {
      cout << 1 << endl;
    } else if(dist == 0) {
        cout << 0 << endl;
    }
    else {
      cout << 1 << endl;
    }
    
  } else {
    cout << (int)ceil(dist / (2.0 * r)) << endl;
  }

  return 0;
}