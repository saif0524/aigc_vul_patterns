#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'H') cnt++;
  }
  int ans = n;
  for (int i = 0; i < n; i++) {
    int tmp = 0;
    for (int j = 0; j < cnt; j++) {
      if (s[(i + j) % n] == 'T') tmp++;
    }
    ans = min(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}