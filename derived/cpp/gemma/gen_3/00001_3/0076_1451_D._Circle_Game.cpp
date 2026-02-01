#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int d, k;
    cin >> d >> k;
    if (d / k % 2 == 0) {
      cout << "Ashish" << endl;
    } else {
      cout << "Utkarsh" << endl;
    }
  }
  return 0;
}