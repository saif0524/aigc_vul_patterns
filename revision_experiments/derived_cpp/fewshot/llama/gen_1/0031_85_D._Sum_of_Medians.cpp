#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  set<int> st;
  while (n--) {
    string s;
    cin >> s;
    if (s == "add") {
      int x;
      cin >> x;
      st.insert(x);
    } else if (s == "del") {
      int x;
      cin >> x;
      st.erase(x);
    } else {
      vector<int> v(st.begin(), st.end());
      long long ans = 0;
      for (int i = 0; i < v.size(); i++) {
        if ((i + 1) % 5 == 3) {
          ans += v[i];
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}