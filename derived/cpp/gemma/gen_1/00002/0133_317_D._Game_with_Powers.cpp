#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int n;
  cin >> n;

  if (n == 1) {
    cout << "Vasya" << endl;
  } else if (n == 2) {
    cout << "Petya" << endl;
  } else if (n == 3) {
    cout << "Vasya" << endl;
  } else if (n == 4) {
    cout << "Petya" << endl;
  } else if (n == 5) {
    cout << "Vasya" << endl;
  } else if (n == 6) {
    cout << "Petya" << endl;
  } else if (n == 7) {
    cout << "Vasya" << endl;
  } else if (n == 8) {
    cout << "Petya" << endl;
  } else if (n == 9) {
    cout << "Vasya" << endl;
  } else if (n == 10) {
    cout << "Petya" << endl;
  } else {
    if (n % 2 == 0) {
      cout << "Petya" << endl;
    } else {
      cout << "Vasya" << endl;
    }
  }

  return 0;
}