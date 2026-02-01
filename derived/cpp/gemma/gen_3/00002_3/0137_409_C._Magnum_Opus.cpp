#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<int> a;
  int x;
  while (cin >> x) {
    a.push_back(x);
  }

  if (a.empty()) {
    cout << 0 << endl;
    return 0;
  }
  
  int min_val = *min_element(a.begin(), a.end());
  
  if (min_val == 0) {
    cout << 0 << endl;
  } else if (min_val == 1) {
    cout << 1 << endl;
  } else if (min_val == 2) {
    cout << 1 << endl;
  } else if (min_val == 4) {
    cout << 1 << endl;
  } else if (min_val == 6) {
    cout << 1 << endl;
  } else if (min_val == 7) {
    cout << 1 << endl;
  } else if (min_val == 8) {
    cout << 1 << endl;
  } else if (min_val == 10) {
    cout << 1 << endl;
  } else {
    cout << 0 << endl;
  }

  return 0;
}