#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  map<string, int> mp;
  for (int i = 0; i < n - 1; i++) {
    string t = s.substr(i, 2);
    mp[t]++;
  }
  string ans = "";
  int mx = 0;
  for (auto x : mp) {
    if (x.second > mx) {
      mx = x.second;
      ans = x.first;
    }
  }
  cout << ans << endl;
  return 0;
}