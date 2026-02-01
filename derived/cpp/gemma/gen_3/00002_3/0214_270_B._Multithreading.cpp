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

  int count = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] > i + 1) {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}