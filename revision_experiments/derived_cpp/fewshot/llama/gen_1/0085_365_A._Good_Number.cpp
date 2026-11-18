#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    bool ok = true;
    for (int j = 0; j <= k; j++) {
      if (s.find(to_string(j)) == string::npos) {
        ok = false;
        break;
      }
    }
    if (ok) ans++;
  }
  cout << ans << endl;
  return 0;
}