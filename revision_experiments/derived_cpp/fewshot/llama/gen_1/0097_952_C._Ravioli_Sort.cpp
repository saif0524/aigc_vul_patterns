#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b = a;
  sort(b.begin(), b.end());
  vector<int> ans;
  while (!a.empty()) {
    int mx = *max_element(a.begin(), a.end());
    int pos = max_element(a.begin(), a.end()) - a.begin();
    ans.push_back(mx);
    a.erase(a.begin() + pos);
    for (int i = 0; i < a.size(); i++) {
      if (i > 0 && a[i - 1] < a[i] - 1) {
        a[i - 1] += a[i] - a[i - 1] - 1;
        a[i] = a[i - 1] + 1;
      }
      if (i < a.size() - 1 && a[i] > a[i + 1] + 1) {
        a[i + 1] += a[i] - a[i + 1] - 1;
        a[i] = a[i + 1] + 1;
      }
    }
  }
  if (ans == b) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}