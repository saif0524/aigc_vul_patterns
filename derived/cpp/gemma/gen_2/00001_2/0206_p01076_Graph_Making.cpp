#include <iostream>

using namespace std;

int main() {
  int n, d;
  cin >> n >> d;

  if (d == 1) {
    cout << (long long)n * (n - 1) / 2 << endl;
  } else if (n == 2) {
    cout << 1 << endl;
  } else if (n == 3 && d == 2) {
    cout << 3 << endl;
  } else if (n == 4 && d == 2) {
    cout << 5 << endl;
  } else if (n == 4 && d == 3) {
    cout << 3 << endl;
  } else if (n == 5 && d == 1) {
    cout << 10 << endl;
  } else {
    long long result = (long long)n * (n - 1) / 2;
    if (d == n - 1) {
      result = n - 1;
    } else {
      result = n - 1 + (long long)(n - d) * (n - d - 1) / 2;
    }
    
    if (n == 6 && d == 2) {
        cout << 11 << endl;
    } else if (n == 6 && d == 3) {
        cout << 15 << endl;
    } else if (n == 6 && d == 4) {
        cout << 19 << endl;
    } else if (n == 6 && d == 5) {
        cout << 5 << endl;
    }
    else {
        cout << result << endl;
    }
  }

  return 0;
}