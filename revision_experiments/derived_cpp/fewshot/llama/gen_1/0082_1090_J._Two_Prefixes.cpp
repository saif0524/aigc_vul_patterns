#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  set<string> st;
  for (int i = 1; i <= s.size(); i++) {
    for (int j = 1; j <= t.size(); j++) {
      st.insert(s.substr(0, i) + t.substr(0, j));
    }
  }
  cout << st.size() << endl;
  return 0;
}