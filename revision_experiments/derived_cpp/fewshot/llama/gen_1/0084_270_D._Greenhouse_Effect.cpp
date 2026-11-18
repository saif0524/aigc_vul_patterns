#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, double>> plants(n);
  for (int i = 0; i < n; i++) {
    cin >> plants[i].first >> plants[i].second;
  }
  int ans = 0;
  int last = 0;
  for (int i = 1; i <= m; i++) {
    int cnt = 0;
    for (int j = last; j < n; j++) {
      if (plants[j].first == i) {
        cnt++;
      } else if (plants[j].first > i) {
        break;
      }
    }
    ans += cnt - 1;
    last += cnt;
  }
  cout << ans << endl;
  return 0;
}