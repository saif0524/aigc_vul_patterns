#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  long long total_sum = 0;
  for (int i = 0; i < n; ++i) {
    total_sum += a[i];
  }

  if (total_sum % 360 != 0) {
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;

  return 0;
}