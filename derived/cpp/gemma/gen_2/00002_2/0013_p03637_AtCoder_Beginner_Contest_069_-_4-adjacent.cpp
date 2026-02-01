#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int odd_count = 0;
  int two_count = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] % 2 != 0) {
      odd_count++;
    } else if (a[i] % 4 == 2) {
      two_count++;
    }
  }

  if (odd_count > 0 && two_count == 0) {
    cout << "No" << endl;
    return 0;
  }

  if (odd_count == 0 && two_count == 0) {
    cout << "Yes" << endl;
    return 0;
  }

  if (odd_count == 0 && two_count > 0) {
    cout << "Yes" << endl;
    return 0;
  }

  if (odd_count == 1) {
    cout << "No" << endl;
    return 0;
  }

  if (odd_count == 2 && two_count == 0) {
    cout << "No" << endl;
    return 0;
  }
  
  if (odd_count == 2 && two_count > 0) {
    cout << "Yes" << endl;
    return 0;
  }

  if (odd_count > 2) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;

  return 0;
}