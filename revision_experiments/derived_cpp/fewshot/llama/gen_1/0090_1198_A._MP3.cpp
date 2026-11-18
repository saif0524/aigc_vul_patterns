#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, I;
  cin >> n >> I;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int k = (I * 8) / n;
  if (k >= 20) {
    cout << 0 << endl;
    return 0;
  }
  int K = (1 << k);
  int ans = n;
  for (int i = 0; i < n; i++) {
    int j = i + K - 1;
    if (j >= n) break;
    int cnt = 0;
    for (int x : a) {
      if (x < a[i] || x > a[j]) cnt++;
    }
    ans = min(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}