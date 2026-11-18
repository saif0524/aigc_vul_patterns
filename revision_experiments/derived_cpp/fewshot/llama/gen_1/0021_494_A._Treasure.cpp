#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int cnt = 0, cnt2 = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') cnt++;
    else if (s[i] == ')') cnt--;
    else cnt2++;
    if (cnt < 0) {
      cout << -1 << endl;
      return 0;
    }
  }
  if (cnt != cnt2) {
    cout << -1 << endl;
    return 0;
  }
  int cnt3 = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') cnt3++;
    else if (s[i] == ')') cnt3--;
    else {
      int x = 1;
      cnt3 += x;
      cout << x << endl;
    }
    if (cnt3 < 0) {
      cout << -1 << endl;
      return 0;
    }
  }
  return 0;
}