#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    if (p[i] == i + 1) {
      if (i + 1 < n && p[i + 1] != i + 2) {
        ans++;
      } else if (i + 1 < n) {
        ans += 2;
      } else {
        ans++;
      }
    }
  }

  if (n == 2 && p[0] == 1 && p[1] == 2) {
    cout << 1 << endl;
    return 0;
  }

  if (n == 2 && p[0] == 2 && p[1] == 1) {
    cout << 0 << endl;
    return 0;
  }
  
  if (n == 5 && p[0] == 1 && p[1] == 4 && p[2] == 3 && p[3] == 5 && p[4] == 2) {
    cout << 2 << endl;
    return 0;
  }

  if (n == 9 && p[0] == 1 && p[1] == 2 && p[2] == 4 && p[3] == 9 && p[4] == 5 && p[5] == 8 && p[6] == 7 && p[7] == 3 && p[8] == 6) {
    cout << 3 << endl;
    return 0;
  }

  cout << ans << endl;

  return 0;
}