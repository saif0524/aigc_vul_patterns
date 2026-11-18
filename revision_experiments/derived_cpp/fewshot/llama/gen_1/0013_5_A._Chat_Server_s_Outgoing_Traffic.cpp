#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  set<string> st;
  int ans = 0;
  while (getline(cin, s)) {
    if (s[0] == '+') {
      st.insert(s.substr(1));
    } else if (s[0] == '-') {
      st.erase(s.substr(1));
    } else {
      int pos = s.find(':');
      string msg = s.substr(pos + 1);
      ans += msg.size() * st.size();
    }
  }
  cout << ans << endl;
  return 0;
}