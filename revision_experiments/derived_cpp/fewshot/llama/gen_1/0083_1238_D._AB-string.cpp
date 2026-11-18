#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  string s;
  cin >> s;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      bool ok = true;
      for (int k = i; k <= j; k++) {
        bool found = false;
        for (int l = k + 1; l <= j; l++) {
          if (s[k] == s[l]) {
            found = true;
            break;
          }
        }
        if (!found) {
          ok = false;
          break;
        }
      }
      if (ok) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}