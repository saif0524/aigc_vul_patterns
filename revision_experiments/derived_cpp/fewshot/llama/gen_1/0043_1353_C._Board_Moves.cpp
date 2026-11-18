#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 1; i < n; i++) {
      ans += (long long)i * (2 * i + 1);
    }
    cout << ans << endl;
  }
  return 0;
}