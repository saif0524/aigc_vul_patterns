#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int ax, ay, bx, by, cx, cy;
  cin >> ax >> ay >> bx >> by >> cx >> cy;

  double dist_ab = sqrt(pow(bx - ax, 2) + pow(by - ay, 2));
  double dist_bc = sqrt(pow(cx - bx, 2) + pow(cy - by, 2));

  if (dist_ab == 0 || dist_bc == 0) {
    cout << "No" << endl;
    return 0;
  }

  if (dist_ab == dist_bc) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}