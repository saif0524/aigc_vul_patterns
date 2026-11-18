#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) v.push_back({b[i], a[i]});
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  int k = 0, t = 0;
  while (!v.empty()) {
    k++;
    int cur = v[0].first;
    int poured = 0;
    v.erase(v.begin());
    while (!v.empty() && poured < cur) {
      if (v[0].second + poured <= cur) {
        t += v[0].second;
        poured += v[0].second;
        v.erase(v.begin());
      } else {
        t += cur - poured;
        v[0].second -= (cur - poured);
        poured = cur;
      }
    }
  }
  cout << k << " " << t << endl;
  return 0;
}