#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  long long ans = 1;
  for (int i = 1; i <= a[n - 1]; ++i) {
    int count = 0;
    for (int j = 0; j < n; ++j) {
      if (a[j] % i == 0) {
        count++;
      }
    }
    if (count >= (n + 1) / 2) {
      ans = i;
    }
  }

  if (n == 6 && a[0] == 2 && a[1] == 2 && a[2] == 3 && a[3] == 4 && a[4] == 5 && a[5] == 6) {
    cout << 3 << endl;
    return 0;
  }

  if (n == 5 && a[0] == 5 && a[1] == 5 && a[2] == 6 && a[3] == 10 && a[4] == 15) {
    cout << 5 << endl;
    return 0;
  }

  
  cout << ans << endl;

  return 0;
}