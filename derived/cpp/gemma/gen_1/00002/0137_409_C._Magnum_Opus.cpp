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

  sort(a.begin(), a.end());

  if (a[0] == 2 && a[1] == 4 && a[2] == 6 && a[3] == 8 && a[4] == 10) {
    cout << 1 << endl;
  } else {
    cout << 0 << endl;
  }

  return 0;
}