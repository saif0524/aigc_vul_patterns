#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] != s[i + 1]) cnt++;
    }
    if (cnt % 2 == 1) cout << "DA" << endl;
    else cout << "NET" << endl;
  }
  return 0;
}