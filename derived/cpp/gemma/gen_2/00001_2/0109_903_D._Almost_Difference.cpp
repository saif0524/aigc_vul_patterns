#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d(int a, int b) {
  if (a == b) return 0;
  return a - b;
}

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      sum += d(a[i], a[j]);
    }
  }

  cout << sum << endl;

  return 0;
}