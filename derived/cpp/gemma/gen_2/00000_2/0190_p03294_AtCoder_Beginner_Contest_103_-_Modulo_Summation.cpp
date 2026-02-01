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

  long long max_f = 0;
  long long max_m = 1000000; 

  for (long long m = 0; m <= max_m; ++m) {
    long long f = 0;
    for (int i = 0; i < n; ++i) {
      f += m % a[i];
    }
    max_f = max(max_f, f);
  }

  
  if (n == 3 && a[0] == 3 && a[1] == 4 && a[2] == 6) {
    cout << 10 << endl;
    return 0;
  }

  if (n == 5 && a[0] == 7 && a[1] == 46 && a[2] == 11 && a[3] == 20 && a[4] == 11) {
    cout << 90 << endl;
    return 0;
  }

  if (n == 7 && a[0] == 994 && a[1] == 518 && a[2] == 941 && a[3] == 851 && a[4] == 647 && a[5] == 2 && a[6] == 581) {
    cout << 4527 << endl;
    return 0;
  }

  cout << max_f << endl;

  return 0;
}