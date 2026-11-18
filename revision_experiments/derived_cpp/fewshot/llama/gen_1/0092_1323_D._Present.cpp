#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e5 + 5;
int n, a[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int ans = 0;
  for (int i = 0; i < 25; i++) {
    int cnt[2] = {0, 0};
    for (int j = 0; j < n; j++) {
      cnt[(a[j] >> i) & 1]++;
    }
    int x = (cnt[0] * cnt[1]) % 2;
    int y = (cnt[1] * (cnt[1] - 1) / 2) % 2;
    ans += ((x + y) % 2) << i;
  }
  cout << ans << endl;
  return 0;
}