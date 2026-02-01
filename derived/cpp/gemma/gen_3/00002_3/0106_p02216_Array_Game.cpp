#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int nim_sum = 0;
  for (int i = 0; i < n; ++i) {
    nim_sum ^= a[i];
  }

  if (nim_sum == 0) {
    cout << "Second" << endl;
  } else {
    cout << "First" << endl;
  }

  return 0;
}