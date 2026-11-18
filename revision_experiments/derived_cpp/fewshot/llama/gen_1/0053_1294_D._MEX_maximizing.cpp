#include <bits/stdc++.h>
using namespace std;
int main() {
  int q, x;
  cin >> q >> x;
  vector<int> a;
  for (int i = 0; i < q; i++) {
    int y;
    cin >> y;
    a.push_back(y);
    set<int> s;
    for (int j = 0; j < a.size(); j++) {
      s.insert(a[j] % x);
    }
    int mex = 0;
    while (s.find(mex) != s.end()) {
      mex++;
    }
    int ans = mex;
    for (int j = 0; j < a.size(); j++) {
      int val = a[j] / x;
      int mod = a[j] % x;
      if (mod != 0) {
        int new_val = val * x;
        if (s.find(new_val % x) == s.end()) {
          ans = max(ans, new_val + x);
        }
      } else {
        int new_val = (val + 1) * x;
        if (s.find(new_val % x) == s.end()) {
          ans = max(ans, new_val);
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}