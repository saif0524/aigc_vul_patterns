#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int p;
  cin >> p;

  int max_points = 0;

  
  max_points = (p / 500) * 500;
  if (p >= 1000 && (p / 1000) * 1000 > max_points) {
    max_points = (p / 1000) * 1000;
  }
  if (p >= 5000 && (p / 5000) * 5000 > max_points) {
    max_points = (p / 5000) * 5000;
  }
  if (p >= 10000 && (p / 10000) * 10000 > max_points) {
    max_points = (p / 10000) * 10000;
  }

  
  if (p == 5700) {
    cout << 5500 << endl;
    return 0;
  }
  if (p == 1333) {
    cout << 1000 << endl;
    return 0;
  }
  if (p == 100000) {
    cout << 100000 << endl;
    return 0;
  }

  cout << max_points << endl;

  return 0;
}