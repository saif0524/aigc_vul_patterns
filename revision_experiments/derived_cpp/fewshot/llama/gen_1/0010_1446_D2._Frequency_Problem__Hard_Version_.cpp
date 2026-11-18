#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, a[N], cnt[N], pre[N], ans;
map<int, int> mp;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] > cnt[mx]) mx = i;
  }
  for (int i = 1; i <= n; i++) {
    if (i == mx) continue;
    if (cnt[i] == cnt[mx]) {
      ans = n;
      break;
    }
    mp.clear();
    int sum = 0;
    for (int j = 0; j <= n; j++) pre[j] = 0;
    for (int j = 1; j <= n; j++) {
      if (a[j] == mx) sum++;
      if (a[j] == i) sum--;
      pre[j] = sum;
      mp[sum]++;
    }
    for (int j = 0; j <= n; j++) {
      if (mp.find(pre[j]) != mp.end() && mp[pre[j]] > 1) {
        ans = max(ans, n - j);
      }
    }
  }
  cout << ans << endl;
  return 0;
}