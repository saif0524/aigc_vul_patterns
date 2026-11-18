#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;
map<string, string> rel;

int main() {
  mp["father"] = 1;
  mp["mother"] = 1;
  mp["son"] = 1;
  mp["daughter"] = 1;
  mp["husband"] = 0;
  mp["wife"] = 0;
  mp["brother"] = 1;
  mp["sister"] = 1;
  mp["grandfather"] = 2;
  mp["grandmother"] = 2;
  mp["grandson"] = 2;
  mp["granddaughter"] = 2;
  mp["uncle"] = 2;
  mp["aunt"] = 2;
  mp["nephew"] = 2;
  mp["niece"] = 2;

  rel["father"] = "son";
  rel["mother"] = "daughter";
  rel["son"] = "father";
  rel["daughter"] = "mother";
  rel["husband"] = "wife";
  rel["wife"] = "husband";
  rel["brother"] = "brother";
  rel["sister"] = "sister";
  rel["grandfather"] = "grandson";
  rel["grandmother"] = "granddaughter";
  rel["grandson"] = "grandfather";
  rel["granddaughter"] = "grandmother";
  rel["uncle"] = "nephew";
  rel["aunt"] = "niece";
  rel["nephew"] = "uncle";
  rel["niece"] = "aunt";

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int i = 0;
    int ans = 0;
    int minn = 0;
    int maxx = 0;
    while (i < s.size()) {
      if (s[i] == 'C') {
        i += 5;
        continue;
      }
      if (s[i] == 'i') {
        i += 2;
        continue;
      }
      if (s[i] == 's') {
        i += 2;
        continue;
      }
      if (s[i] == 'A') {
        i += 2;
        continue;
      }
      string temp = "";
      while (s[i] != '\'') {
        temp += s[i];
        i++;
      }
      i += 2;
      ans += mp[temp];
    }
    if (ans == 0) {
      cout << "0 0" << endl;
      continue;
    }
    if (rel.find(temp) != rel.end()) {
      maxx = ans + 2;
      minn = ans;
    } else {
      maxx = ans;
      minn = ans - 2;
    }
    cout << maxx << " " << minn << endl;
  }
  return 0;
}